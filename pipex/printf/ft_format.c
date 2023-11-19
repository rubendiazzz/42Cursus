/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:46 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/11/04 16:31:47 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	local_count;

	local_count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		local_count += ft_putchar(*str);
		str++;
	}
	return (local_count);
}

int	ft_putnbr(long n)
{
	int	local_count;

	local_count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		local_count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		local_count += ft_putnbr(n / 10);
	local_count += ft_putchar((n % 10) + '0');
	return (local_count);
}

int	ft_puthex(uintptr_t n, int is_uppercase, int include_prefix)
{
	int		local_count;
	char	hex_digit;

	local_count = 0;
	if (n == 0)
	{
		if (include_prefix)
			local_count += ft_putstr("0x");
		return (local_count + ft_putchar('0'));
	}
	if (include_prefix)
		local_count += ft_putstr("0x");
	if (n >= 16)
		local_count += ft_puthex(n / 16, is_uppercase, 0);
	hex_digit = n % 16;
	if (hex_digit > 9)
	{
		if (is_uppercase)
			local_count += ft_putchar('A' + hex_digit - 10);
		else
			local_count += ft_putchar('a' + hex_digit - 10);
	}
	else
		local_count += ft_putchar('0' + hex_digit);
	return (local_count);
}
