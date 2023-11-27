/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:02:16 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/27 10:05:29 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	setup_redirections(int new_in, int new_out)
{
	if (new_in >= 0)
	{
		dup2(new_in, STDIN_FILENO);
		close(new_in);
	}
	if (new_out >= 0)
	{
		dup2(new_out, STDOUT_FILENO);
		close(new_out);
	}
}

void	execute_command(char *cmd[], int fds[], char *envp[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		setup_redirections(fds[0], fds[1]);
		if (execve(cmd[0], cmd, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
