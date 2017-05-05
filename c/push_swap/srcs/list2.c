/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:47:19 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 19:59:51 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ft_del_list(t_list **list)
{
	ft_free_elem(*list);
	free(*list);
	*list = NULL;
}

void		ft_free_elem(t_list *list)
{
	t_list	*tmp;
	t_list	*next_elem;

	tmp = list->next;
	while (tmp != list)
	{
		next_elem = tmp->next;
		free(tmp);
		tmp = next_elem;
	}
}

void		ft_remove_elem(t_list *list)
{
	list->prev->next = list->next;
	list->next->prev = list->prev;
	free(list);
}

void		ft_removefirst_elem(t_list *list)
{
	if (list->next != list)
	{
		list->len--;
		ft_remove_elem(list->next);
	}
}

void		ft_removelast_elem(t_list *list)
{
	if (list->prev != list)
	{
		list->len--;
		ft_remove_elem(list->prev);
	}
}
