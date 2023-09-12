/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:31:44 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/12 11:20:23 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ptr;

	if (!dst && !src)
		return (0);
	ptr = dst;
	while (n--)
		*(char *) dst++ = *(char *) src++;
	return (ptr);
}
