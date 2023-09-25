/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:41:32 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/25 18:33:39 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;
	int		in_word;

	if (c == '\0')
		return (1);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_memory(char **lst, int i)
{
	while (i >= 0)
	{
		free(lst[i]);
		i--;
	}
	free(lst);
}

static int	allocate_single_word(char **lst, int i, const char **s, char c)
{
	size_t	word_len;

	if (c == '\0')
		word_len = ft_strlen(*s);
	else if (ft_strchr(*s, c))
		word_len = ft_strchr(*s, c) - *s;
	else
		word_len = ft_strlen(*s);
	lst[i] = ft_substr(*s, 0, word_len);
	if (!lst[i])
	{
		free_memory(lst, i - 1);
		return (0);
	}
	*s += word_len;
	return (1);
}

static int	allocate_words(char **lst, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s && c != '\0')
			s++;
		if (*s == '\0')
			break ;
		if (!allocate_single_word(lst, i, &s, c))
			return (0);
		i++;
		while (*s == c && c != '\0')
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	lst = malloc((word_count + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	if (allocate_words(lst, s, c) == 0)
		return (NULL);
	lst[word_count] = NULL;
	return (lst);
}
