/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:46:57 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/12 15:10:03 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int				ft_pipex_child(t_pipex *pipex, int *fd)
{
	int		file1;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	file1 = open(pipex->file1, O_RDONLY);
	if (file1 == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(pipex->file1, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	dup2(file1, 0);
	close(file1);
	execve(pipex->cmd1, ft_split(pipex->cmd1, ' '), pipex->envp);
	return (-1);
}

int				ft_pipex_parent(t_pipex *pipex, int *fd)
{
	int		file2;

	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	file2 = open(pipex->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(pipex->file2, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	dup2(file2, 1);
	close(file2);
	execve(pipex->cmd2, ft_split(pipex->cmd2, ' '), pipex->envp);
	return (-1);
}

int				ft_pipex(t_pipex *pipex)
{
	int		fd[2];
	int		pid;
	int		status;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		exit(ft_pipex_child(pipex, fd));
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (ft_pipex_parent(pipex, fd));
	}
	return (-1);
}

int		main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	if (!(pipex = (t_pipex *)malloc(sizeof(t_pipex))))
		return (1);
	pipex->envp = envp;
	pipex->file1 = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->file2 = argv[4];
	if (ft_pipex(pipex) == -1)
		return (1);
	return (0);
}
