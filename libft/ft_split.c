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

char **ft_split(char const *s, char c)
{
	int 	j; // COUNTER VAR 
	int 	i; // INDEX VAR
	int 	length_of_str;
	void 	allocator;

	i = 0;
	counter = 0;
	length_of_str = ft_strlen (s); // I set the value of strlen(s) to length_of_str variable.
	while (s[i] != '\0') // Loop to see if the s[i] is equal to 'c', if it is, it gets out, if not, i++;
	{
		if (s[i] == c)
			return ;
		else if (s[i] != c)
			i++;
	}
	allocator = ft_calloc((s[i] + 1) * sizeof(char *)); // Allocate memory with ft_calloc for the number of substring of char pointers.
	i = 0;
	j = length_of_str - 1;
	while (length_of_str != NULL)
	{
		ft_split[i][j];
		i++;
		j--;
		if (ft_split[i][j] == c)
		{
			ft_substr(s, s[i], length_of_str);
		}
	}
}
