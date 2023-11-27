/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:07:18 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/27 10:16:32 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_command(int fd_input, int *pipefd, char **av, char **envp)
{
	pid_t	child1_pid;
	char	*cmd1[];

	cmd1[] = {"/bin/sh", "-c", av[2], NULL};
	child1_pid = fork();
	if (child1_pid == 0)
	{
		setup_redirections(fd_input, pipefd[1]);
		execute_command(cmd1, (int[]){fd_input, pipefd[1]}, envp);
	}
	else if (child1_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	execute_second_command(int fd_output, int *pipefd, char **av,
		char **envp)
{
	pid_t	child2_pid;
	char	*cmd2[];

	cmd2[] = {"/bin/sh", "-c", av[3], NULL};
	child2_pid = fork();
	if (child2_pid == 0)
	{
		setup_redirections(pipefd[0], fd_output);
		execute_command (cmd2, (int[]){pipefd[0], fd_output}, envp);
	}
	else if (child2_pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	fd_input;
	int	fd_output;
	int	pipefd[2];

	if (ac != 5)
	{
		ft_putstr("Error: Bad number of arguments\n");
		exit(EXIT_FAILURE);
	}
	fd_input = open_file(av[1], O_RDONLY, 0);
	fd_output = open_file(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	init_pipe(pipefd);
	execute_first_command(fd_input, pipefd, av, envp);
	execute_second_command(fd_output, pipefd, av, envp);
	close_fds((int[]){fd_input, fd_output, pipefd[0], pipefd[1]}, 4);
	wait_for_child();
	return (0);
}
