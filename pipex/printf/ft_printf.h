/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:54:44 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/24 09:55:50 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/*
** @brief Prints a single character to standard output.
** @param c The character to print.
** @param count Pointer to the count of printed characters.
*/
int		ft_putchar(char c);

/*
** @brief Prints a string to standard output.
** @param str The string to print.
** @param count Pointer to the count of printed characters.
*/
int		ft_putstr(const char *str);

/*
** @brief Prints a long integer to standard output.
** @param n The long integer to print.
** @param count Pointer to the count of printed characters.
*/
int		ft_putnbr(long n);

/*
** @brief Prints a uintptr_t integer to standard output.
** @param n The integer to print.
** @param count Pointer to the count of printed characters.
*/
void	ft_putptr(uintptr_t n, int *count);

/*
** @brief Prints a uintptr_t integer in hexadecimal format to standard output.
** @param n The integer to print.
** @param is_uppercase Flag to determine if letters should be uppercase.
** @param count Pointer to the count of printed characters.
** @param include_prefix Whether or not to include the "0x" prefix.
*/
int		ft_puthex(uintptr_t n, int is_uppercase, int include_prefix);

/*
** @brief Handles the format specifier and prints the corresponding argument.
** @param specifier The format specifier ('c', 's', 'p', 'd', 'i', 'u', 'x',
** 'X', '%').
** @param args Pointer to the variable argument list.
** @param count Pointer to the count of printed characters.
*/
int		handle_format(char specifier, va_list args);

/*
** @brief Mimics the printf function from the C standard library.
** @param format The format string.
** @return The number of characters printed.
*/
int		ft_printf(const char *format, ...);

/**
 * @brief Calculates the length of a string.
 * @param s The string.
 * @return The length of the string.
 * @note This function is not part of the printf implementation.
 * It is only used to make the code more readable.
 */
size_t	ft_strlen(const char *s);

#endif
