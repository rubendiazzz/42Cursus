/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:15:42 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/10/01 16:33:03 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

t_print *ft_initialise_tab(t_print *tab)                       
{                       
      tab->wdt = 0;        // we set everything to 0, false        
      tab->prc = 0;                        
      tab->zero = 0;                        
      tab->pt = 0;                        
      tab->sign = 0;                        
      tab->tlngth = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;                        
      tab->space = 0;                        
      return (tab);                       
}
int ft_printf(const char *format, ...)
{
   t_print *tab;
                       
   tab = (t_print *)malloc(sizeof(t_print));                        
   if (!tab)                         
       return (-1);
   ft_initialise_tab(tab)
}
