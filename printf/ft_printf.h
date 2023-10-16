/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:09:13 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/16 17:10:34 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Prints a single character to standard output.
 * @param c The character to print.
 * @param count Pointer to the count of printed characters.
 */
void	ft_putchar(char c, int *count);

/**
 * @brief Prints a string to standard output.
 * @param str The string to print.
 * @param count Pointer to the count of printed characters.
 */
void	ft_putstr(const char *str, int *count);

/**
 * @brief Prints a long integer to standard output.
 * @param n The long integer to print.
 * @param count Pointer to the count of printed characters.
 */
void	ft_putnbr(long n, int *count);

/**
 * @brief Prints a uintptr_t integer in hexadecimal format to standard output.
 * @param n The integer to print.
 * @param is_uppercase Flag to determine if letters should be in uppercase.
 * @param count Pointer to the count of printed characters.
 */
void	ft_puthex(uintptr_t n, int is_uppercase, int *count,
			int include_prefix);

/**
 * @brief Handles the format specifier and prints the corresponding argument.
 * @param specifier The format specifier ('c', 's', 'p', 'd', 'i', 'u', 'x',
	'X', '%').
 * @param args Pointer to the variable argument list.
 * @param count Pointer to the count of printed characters.
 */
void	handle_format(char specifier, va_list args, int *count);

/**
 * @brief Mimics the printf function from the C standard library.
 * @param format The format string.
 * @return The number of characters printed.
 */
int		ft_printf(const char *format, ...);

#endif
