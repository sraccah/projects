/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:55:28 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 07:54:33 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ft_pa_ps(t_list *list, t_list *list1)
{
	if (list1->next != list1)
	{
		ft_head_list(list, list1->next->val);
		ft_removefirst_elem(list1);
		write(1, " pa", 3);
	}
}

void		ft_pb_ps(t_list *list, t_list *list1, int count)
{
	if (list->next != list)
	{
		ft_head_list(list1, list->next->val);
		ft_removefirst_elem(list);
		if (count == 0)
			write(1, "pb", 2);
		else
			write(1, " pb", 3);
	}
}

void		ft_rrr_ps(t_list *list, t_list *list1)
{
	if (list->len >= 2)
	{
		ft_head_list(list, list->prev->val);
		ft_remove_elem(list->prev);
	}
	if (list1->len >= 2)
	{
		ft_head_list(list1, list1->prev->val);
		ft_remove_elem(list1->prev);
	}
	write(1, " rrr", 3);
}

void		ft_print_list_ps(t_list *list)
{
	t_list	*tmp;

	tmp = list->next;
	while (tmp != list)
	{
		ft_putnbr(tmp->val);
		tmp = tmp->next;
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}
