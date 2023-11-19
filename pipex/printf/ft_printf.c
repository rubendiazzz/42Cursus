/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:08:34 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:27 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char specifier, va_list args)
{
	int	local_count;

	local_count = 0;
	if (specifier == 'c')
		local_count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		local_count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		local_count += ft_puthex((uintptr_t)va_arg(args, void *), 0, 1);
	else if (specifier == 'd' || specifier == 'i')
		local_count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		local_count += ft_putnbr((unsigned int)va_arg(args, unsigned int));
	else if (specifier == 'x')
		local_count += ft_puthex(va_arg(args, unsigned int), 0, 0);
	else if (specifier == 'X')
		local_count += ft_puthex(va_arg(args, unsigned int), 1, 0);
	else if (specifier == '%')
		local_count += ft_putchar('%');
	return (local_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
