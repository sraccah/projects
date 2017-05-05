/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:58:48 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 10:28:02 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ft_sa_ps(t_list *list, int count)
{
	t_list	*tmp;

	if (list->len >= 2)
	{
		tmp = list->root;
		tmp = tmp->next;
		ft_swap_elem(tmp, tmp->next);
		if (count == 0)
			write(1, "sa", 2);
		else
			write(1, " sa", 3);
	}
}

void		ft_sb_ps(t_list *list1)
{
	t_list	*tmp;

	if (list1->len >= 2)
	{
		tmp = list1->root;
		tmp = tmp->next;
		ft_swap_elem(tmp, tmp->next);
		write(1, " sb", 3);
	}
}

void		ft_ss_ps(t_list *list, t_list *list1)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (list->len >= 2)
	{
		tmp1 = list->root;
		tmp1 = tmp1->next;
		ft_swap_elem(tmp1, tmp1->next);
	}
	if (list1->len >= 2)
	{
		tmp2 = list1->root;
		tmp2 = tmp2->next;
		ft_swap_elem(tmp2, tmp2->next);
	}
	write(1, " ss", 3);
}
