/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:08:34 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/13 16:43:34 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(char specifier, va_list args, int *count)
{
	if (specifier == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (specifier == 'p')
		ft_puthex((uintptr_t)va_arg(args, void *), 0, count, 1);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (specifier == 'u')
		ft_putnbr((unsigned int)va_arg(args, unsigned int), count);
	else if (specifier == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, count, 0);
	else if (specifier == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, count, 0);
	else if (specifier == '%')
		ft_putchar('%', count);
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
			handle_format(*format, args, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
