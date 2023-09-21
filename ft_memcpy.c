/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:31:44 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/20 12:01:55 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (ret);
}

/*int	main()
{
	char	orig[] = "ABCDE";
	char	orig2[] = "ABCDE";
	char	dest[] = "abcde";
	char	dest2[] = "abcde";
	printf("%s\n", ft_memcpy(dest, orig, 7));
}*/