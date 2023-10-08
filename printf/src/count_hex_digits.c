/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hex_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:24:20 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/05 12:24:46 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	count_hex_digits(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}
