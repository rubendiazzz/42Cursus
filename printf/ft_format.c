/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:46 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/11 16:17:04 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(const char *str, int *count)
{
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, count);
		str++;
	}
}

void	ft_putnbr(long n, int *count)
{
	int		i;
	char	buffer[20];

	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar(buffer[i], count);
}

void	ft_puthex(uintptr_t n, int is_uppercase, int *count, int include_prefix)
{
	char	*hex_digits;
	int		i;
	char	buffer[20];

	if (n == 0 && include_prefix)
	{
		ft_putstr("0x0", count);
		return ;
	}
	i = 0;
	if (is_uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	while (n > 0)
	{
		buffer[i++] = hex_digits[n % 16];
		n /= 16;
	}
	if (include_prefix)
		ft_putstr("0x", count);
	while (--i >= 0)
		ft_putchar(buffer[i], count);
}
