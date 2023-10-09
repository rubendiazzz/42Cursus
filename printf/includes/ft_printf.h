/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:08:48 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/09 16:51:46 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

/**
 * @brief This is a replica of the function printf in C standard library.
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int		ft_printf(const char *format, ...);

/**
 * @brief This function will help with the format specifiers and 
 * looking for what type are them.
 * 
 * @param specifier 
 * @param args 
 * @return int 
 */
int		handle_format(char specifier, va_list args);

/**
 * @brief This function will handle the behaviour of printf
 * when a string is passed.
 * 
 * @param str 
 * @return int 
 */
int		handle_string(char *str);

/**
 * @brief This functions will handle the behavior of printf
 * when an only char is passed.
 * 
 * @param c 
 * @return int 
 */
int		handle_char(char c);

/**
 * @brief This function will handle the behavior when a %p or
 * pointer is passed.
 * 
 * @param ptr 
 * @return int 
 */
int		handle_pointer(void *ptr);

/**
 * @brief This function will handle the behavior of printf when 
 * an integer is passed.
 * 
 * @param num 
 * @return int 
 */
int		handle_integer(int num);

/**
 * @brief This function will handle the behavior of printf when
 * an unsigned is passed.
 * 
 * @param num 
 * @return int 
 */
int		handle_unsigned(unsigned int num);

/**
 * @brief This function will handle the behavior of printf when
 * a HEX is passed.
 * 
 * @param num 
 * @param base 
 * @return int 
 */
int		handle_hex(unsigned int num, char *base);
/**
 * @brief This function will just count the digits passed.
 * 
 * @param n 
 * @return int 
 */
int		count_digits(int n);

/**
 * @brief This function will handle the count of all the HEX digits.
 * 
 * @param n 
 * @return int 
 */
int		count_hex_digits(unsigned long n);

/**
 * @brief This function is the function putnbr but it handles bases.
 * 
 * @param nbr 
 * @param base 
 */
void	ft_putnbr_base(int nbr, char *base);

#endif
