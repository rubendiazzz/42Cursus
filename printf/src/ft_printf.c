/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:15:42 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/05 12:28:05 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_chars;

	i = 0;
	total_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			total_chars += handle_format(format[++i], args);
		else
		{
			ft_printchar(format[i]);
			total_chars++;
		}
		i++;
	}
	va_end(args);
	return (total_chars);
}
