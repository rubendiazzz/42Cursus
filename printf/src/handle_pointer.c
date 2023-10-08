/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:34:23 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/05 12:52:32 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	handle_pointer(void *ptr)
{
	int	char_count;

	ft_putstr_fd("0x", 1);
	ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	char_count = count_hex_digits((unsigned long)ptr) + 2;
	return (char_count);
}
