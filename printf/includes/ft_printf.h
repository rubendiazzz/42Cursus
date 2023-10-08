/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:08:48 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/05 12:46:44 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		handle_format(char specifier, va_list args);
int		handle_string(char *str);
int		handle_char(char c);
int		handle_pointer(void *ptr);
int		handle_integer(int num);
int		handle_unsigned(unsigned int num);
int		handle_hex(unsigned int num, char *base);
int		count_digits(int n);
int		count_hex_digits(unsigned long n);
void	ft_putnbr_base(int nbr, char *base);

#endif
