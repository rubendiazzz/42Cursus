/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:09:24 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/02 12:07:25 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*tmp;

	tmp = b;
	while (len--)
		*(char *)b++ = (unsigned char)c;
	return (tmp);
}
