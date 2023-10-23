/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:46 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/23 16:20:47 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	ssize_t	bytes_written;

	bytes_written = write(1, &c, 1);
	if (bytes_written == -1)
		exit(EXIT_FAILURE);
	(*count)++;
}

void	ft_putstr(const char *str, int *count)
{
	ssize_t	bytes_written;

	if (str == NULL)
	{
		bytes_written = write(1, "(null)", 6);
		if (bytes_written == -1)
		{
			exit(EXIT_FAILURE);
		}
		(*count) += 6;
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, count);
		str++;
	}
}

void	ft_putnbr(long n, int *count)
{
	int		i;
	char	*buffer;

	buffer = (char *)malloc(21 * sizeof(char));
	if (buffer == NULL)
		exit(EXIT_FAILURE);
	if (n == 0)
	{
		ft_putchar('0', count);
		free(buffer);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		ft_putchar(buffer[i], count);
	free(buffer);
}

void	fill_buffer(char *buffer, uintptr_t n, int is_uppercase)
{
	int		i;
	char	hex_digit;

	i = 0;
	while (n > 0)
	{
		hex_digit = n % 16;
		if (hex_digit > 9)
		{
			if (is_uppercase)
				buffer[i] = 'A' + hex_digit - 10;
			else
				buffer[i] = 'a' + hex_digit - 10;
		}
		else
			buffer[i] = '0' + hex_digit;
		i++;
		n /= 16;
	}
	buffer[i] = '\0';
}

void	ft_puthex(uintptr_t n, int is_uppercase, int *count, int include_prefix)
{
	char	buffer[20];
	int		i;

	if (n == 0)
	{
		if (include_prefix)
			ft_putstr("0x", count);
		ft_putchar('0', count);
		return ;
	}
	fill_buffer(buffer, n, is_uppercase);
	if (include_prefix)
		ft_putstr("0x", count);
	i = 0;
	while (buffer[i] != '\0')
		i++;
	while (--i >= 0)
		ft_putchar(buffer[i], count);
}
