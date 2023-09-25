/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:41:54 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/18 13:07:47 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (s1 == NULL || str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && s1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
