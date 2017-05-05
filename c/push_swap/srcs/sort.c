/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 07:02:15 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 09:31:43 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ft_swap_elem(t_list *list, t_list *list1)
{
	int		tmp;

	tmp = list->val;
	list->val = list1->val;
	list1->val = tmp;
}

int			ft_sort_list(t_list *list, t_list *list1)
{
	int		count;

	count = 0;
	while (list->next != list)
	{
		if (list->next->val > list->next->next->val && list->len == 2)
			ft_sa_ps(list, count++);
		if (ft_isminor_list(list))
			ft_pb_ps(list, list1, count);
		else
			ft_ra_ps(list, count);
		if (count == 0)
			count = 1;
	}
	while (list && list1 && list1->next != list1)
		ft_pa_ps(list, list1);
	ft_putchar('\n');
	return (0);
}

int			ft_isminor_list(t_list *list)
{
	int		cur_min;
	t_list	*tmp;

	cur_min = list->next->val;
	tmp = list->next;
	while (tmp != list)
	{
		if (cur_min > tmp->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
