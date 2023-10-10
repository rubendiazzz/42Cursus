/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:08:48 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/10 16:16:34 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

/**
 * @brief Mimics the functionality of the standard C library's printf function.
 *
 * @param format Formatting string
 * @param ... Variable number of arguments
 * @return int Number of characters printed
 */
int		ft_printf(const char *format, ...);

/**
 * @brief Processes format specifiers and identifies their corresponding types.
 *
 * @param specifier Format specifier character
 * @param args Variable argument list
 * @return int Number of characters processed
 */
int		handle_format(char specifier, va_list args);

/**
 * @brief Manages string arguments in printf-compatible behavior.
 *
 * @param str String to print
 * @return int Number of characters printed
 */
int		handle_string(char *str);

/**
 * @brief Manages character arguments in printf-compatible behavior.
 *
 * @param c Character to print
 * @return int Number of characters printed
 */
int		handle_char(char c);

/**
 * @brief Manages pointer arguments, specifically for %p format specifier.
 *
 * @param ptr Pointer to print
 * @return int Number of characters printed
 */
int		handle_pointer(void *ptr);

/**
 * @brief Manages integer arguments in printf-compatible behavior.
 *
 * @param num Integer to print
 * @return int Number of characters printed
 */
int		handle_integer(int num);

/**
 * @brief Manages unsigned integer arguments in printf-compatible behavior.
 *
 * @param num Unsigned integer to print
 * @return int Number of characters printed
 */
int		handle_unsigned(unsigned int num);

/**
 * @brief Manages hexadecimal arguments in printf-compatible behavior.
 *
 * @param num Unsigned integer to convert to hexadecimal
 * @param base Base characters for hexadecimal conversion
 * @return int Number of characters printed
 */
int		handle_hex(unsigned int num, char *base);

/**
 * @brief Counts the digits in an integer.
 *
 * @param n Integer to evaluate
 * @return int Number of digits
 */
int		count_digits(int n);

/**
 * @brief Counts the digits in a hexadecimal number.
 *
 * @param n Unsigned long number to evaluate
 * @return int Number of hexadecimal digits
 */
int		count_hex_digits(unsigned long n);

/**
 * @brief Prints an integer in a specified base.
 *
 * @param nbr Integer to print
 * @param base Base characters for conversion
 */
void	ft_putnbr_base(int nbr, char *base);

#endif
