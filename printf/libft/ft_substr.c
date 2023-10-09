/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:36:21 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/03 16:01:14 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size_to_allocate(size_t str_len, unsigned int start, size_t len)
{
	if (start >= str_len || len == 0)
		return (1);
	if (len > str_len - start)
		return (str_len - start + 1);
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	str_len;
	size_t	size_to_allocate;

	if (!s)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	size_to_allocate = get_size_to_allocate(str_len, start, len);
	tmp = (char *)malloc(size_to_allocate * sizeof(char));
	if (!tmp)
		return (NULL);
	if (start >= str_len)
		tmp[0] = '\0';
	else
		while (i < len && s[start])
			tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
