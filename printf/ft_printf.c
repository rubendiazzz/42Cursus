/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:21:36 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/23 16:21:37 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	tmp;

	tmp = 0;
	while (*s++)
		++tmp;
	return (tmp);
}

void	handle_char(va_list args, int *count)
{
	ft_putchar(va_arg(args, int), count);
}

void	handle_string(va_list args, int *count)
{
	ft_putstr(va_arg(args, char *), count);
}

void	handle_format(char specifier, va_list args, int *count)
{
	if (specifier == 'c')
		handle_char(args, count);
	else if (specifier == 's')
		handle_string(args, count);
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
		{
			ft_putchar(*format, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
