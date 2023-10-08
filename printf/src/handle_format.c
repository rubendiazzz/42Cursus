/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:38:19 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/05 11:39:05 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	handle_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(va_arg(args, int)));
	if (specifier == 's')
		return (handle_string(va_arg(args, char *)));
	if (specifier == 'p')
		return (handle_pointer(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (handle_integer(va_arg(args, int)));
	if (specifier == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (handle_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (specifier == 'X')
		return (handle_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (specifier == '%')
		return (handle_char('%'));
	return (0);
}
