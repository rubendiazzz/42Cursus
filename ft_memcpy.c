/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:31:44 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/21 18:57:07 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (const char *)src;
	if (!tmp_dst || !tmp_src)
		return (NULL);
	while (n--)
	{
		*tmp_dst++ = *tmp_src++;
	}
	return (dst);
}

/*int	main()
{
	char	orig[] = "ABCDE";
	char	orig2[] = "ABCDE";
	char	dest[] = "abcde";
	char	dest2[] = "abcde";
	printf("%s\n", ft_memcpy(dest, orig, 7));
}*/