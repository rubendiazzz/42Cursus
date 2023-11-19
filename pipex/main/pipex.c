/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:55:28 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/15 12:24:18 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Function to handle the first command execution
void execute_cmd1(int pipefd[], char *cmd1, char *envp[])
{
	pid_t pid;


	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// Child process
		close(pipefd[0]); // Close unused read end
		dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
		close(pipefd[1]);
		// Execute cmd1
		char **cmd1_args = ft_split(cmd1, ' '); // Split cmd1 into arguments
		execve(cmd1_args[0], cmd1_args, envp); // Execute cmd1
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

// Function to handle the second command execution
void execute_cmd2(int pipefd[], int fd_out, char *cmd2, char *envp[])
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// Second child process
		close(pipefd[1]); // Close unused write end
		dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
		close(pipefd[0]);
		dup2(fd_out, STDOUT_FILENO); // Redirect stdout to file2
		close(fd_out);
		// Execute cmd2
		char **cmd2_args = ft_split(cmd2, ' '); // Split cmd2 into arguments
		execve(cmd2_args[0], cmd2_args, envp); // Execute cmd2
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

int main(int ac, char *av[], char *envp[])
{
	int fd_in, fd_out, pipefd[2];

	if (ac != 5)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (1);
	}
	fd_in = open(av[1], O_RDONLY);
	if (fd_in < 0)
		perror("Error opening file 1");
	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		perror("Error opening file 2");
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	execute_cmd1(pipefd, av[2], envp); // Execute the first command
	execute_cmd2(pipefd, fd_out, av[3], envp); // Execute the second command
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd_in);
	close(fd_out);
	waitpid(-1, NULL, 0); // Wait for all child processes to finish
	return (0);
}
