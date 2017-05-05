/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:53:42 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 10:26:10 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ft_ra_ps(t_list *list, int count)
{
	if (list->len > 2)
	{
		ft_tail_list(list, list->next->val);
		ft_remove_elem(list->next);
		if (count == 0)
			write(1, "ra", 2);
		else
			write(1, " ra", 3);
	}
}

void		ft_rb_ps(t_list *list1)
{
	if (list1->len > 2)
	{
		ft_tail_list(list1, list1->next->val);
		ft_remove_elem(list1->next);
		write(1, " rb", 3);
	}
}

void		ft_rr_ps(t_list *list, t_list *list1)
{
	if (list->len >= 2)
	{
		ft_tail_list(list, list->next->val);
		ft_remove_elem(list->next);
	}
	if (list1->len >= 2)
	{
		ft_tail_list(list1, list1->next->val);
		ft_remove_elem(list1->next);
	}
	write(1, " rr", 3);
}

void		ft_rra_ps(t_list *list)
{
	if (list->len > 2)
	{
		ft_head_list(list, list->prev->val);
		ft_remove_elem(list->prev);
		write(1, " rra", 3);
	}
}

void		ft_rrb_ps(t_list *list1)
{
	if (list1->len > 2)
	{
		ft_head_list(list1, list1->prev->val);
		ft_remove_elem(list1->prev);
		write(1, " rrb", 3);
	}
}
