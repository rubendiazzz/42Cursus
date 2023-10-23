/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:17:16 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/23 16:22:43 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
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
 * @brief Handles the 'c' format specifier.
 * @param args The variable argument list.
 * @param count Pointer to the count of printed characters.
 */
void	handle_char(va_list args, int *count);

/**
 * @brief Handles the 's' format specifier.
 * @param args The variable argument list.
 * @param count Pointer to the count of printed characters.
 */
void	handle_string(va_list args, int *count);

/**
 * @brief Handles the format specifier and prints the corresponding argument.
 * @param specifier The format specifier ('c', 's', 'p', 'd', 'i', 'u', 'x',
 * 'X', '%').
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

/**
 * @brief Calculates the length of a string.
 * @param s The string.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Prints a hexadecimal number to standard output.
 * @param n The hexadecimal number to print.
 * @param is_uppercase Whether to print the hexadecimal number in uppercase.
 * @param count Pointer to the count of printed characters.
 * @param include_prefix Whether to include the '0x' prefix.
 */
void	ft_puthex(uintptr_t n, int is_uppercase, int *count,
			int include_prefix);

#endif
