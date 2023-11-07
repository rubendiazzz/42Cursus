/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:21:34 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/03 18:05:34 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_start(char *start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

void	handle_read(char **tmp, char **start_str, int fd, int *fd_read)
{
	*fd_read = read(fd, *tmp, BUFFER_SIZE);
	if (*fd_read == -1)
	{
		free(*tmp);
		free(start_str[fd]);
		start_str[fd] = NULL;
	}
	else
	{
		(*tmp)[*fd_read] = '\0';
		start_str[fd] = ft_strjoin(start_str[fd], *tmp);
	}
}

char	*get_next_line(int fd)
{
	char		*tmp;
	int			fd_read;
	static char	*start_str[1024] = {NULL};

	tmp = malloc(1 + BUFFER_SIZE);
	if (!tmp || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(tmp);
		return (NULL);
	}
	fd_read = 1;
	while (!ft_strchr(start_str[fd], '\n') && fd_read)
	{
		handle_read(&tmp, start_str, fd, &fd_read);
		if (fd_read == -1)
			return (NULL);
	}
	free(tmp);
	tmp = ft_readed_line(start_str[fd]);
	start_str[fd] = ft_move_start(start_str[fd]);
	return (tmp);
}
