/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:41:32 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/26 16:03:22 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_substrings(char const *s, char c)
{
	int	i;
	int	count;
	int	in_substring;

	i = 0;
	count = 0;
	in_substring = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_substring = 0;
		}
		i++;
	}
	return (count);
}

char	**allocate_memory(int count)
{
	char	**allocator;

	allocator = (char **)ft_calloc((count + 1), sizeof(char *));
	if (allocator == NULL)
		return (NULL);
	return (allocator);
}

void	fill_substrings(char **allocator, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
			allocator[j++] = ft_substr(s, start, i - start);
	}
	allocator[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**allocator;

	if (s == NULL)
		return (NULL);
	count = count_substrings(s, c);
	allocator = allocate_memory(count);
	if (allocator == NULL)
		return (NULL);
	fill_substrings(allocator, s, c);
	return (allocator);
}
