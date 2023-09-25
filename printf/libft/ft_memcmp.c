/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:20:15 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/21 14:26:47 by rdiaz-fr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dst, const void *str, size_t n)
{
	int				diff;
	unsigned char	*str2;
	unsigned char	*dst2;

	dst2 = (unsigned char *)dst;
	str2 = (unsigned char *)str;
	diff = 0;
	if (n)
	{
		while (n--)
		{
			diff = *dst2++ - *str2++;
			if (diff != 0)
				break ;
		}
	}
	return (diff);
}
