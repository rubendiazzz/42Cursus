/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:37:23 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/27 10:05:01 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

// Function prototypes from childs.c
void execute_command(char *cmd[], int fds[], char *envp[]);
void setup_redirections(int new_in, int new_out);

// Function prototypes from parents.c
void wait_for_child(pid_t child_pid);

// Function prototypes from file_operations.c
int open_file(char *filename, int flags, int perms);
void init_pipe(int pipefd[2]);
void close_fds(int fds[], int size);

// Function prototypes from errors.c
void ft_putstr(char *s);

#endif
