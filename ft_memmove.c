/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:29:59 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/19 15:31:14 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	if (!dst && !src)
		return (0);
	tmp = dst;
	if (dst < src)
		while (len--)
		*(char *)dst++ = *(char *)src++;
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
		*(char *)dst-- = *(char *)src--;
	}		
	return (tmp);
}
