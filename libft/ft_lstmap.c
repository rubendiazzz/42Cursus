/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:42:37 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/09/25 18:51:34 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*x;
	t_list	*new;

	if (!l)
		return (NULL);
	new = ft_lstnew(f(l->content));
	if (!(new))
		return (NULL);
	x = new;
	while (l)
	{
		if (l->next)
		{
			new->next = ft_lstnew(f(l->next->content));
			if (!(new->next))
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			new = new->next;
		}
		l = l->next;
	}
	new->next = NULL;
	return (x);
}