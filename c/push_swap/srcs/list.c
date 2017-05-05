/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:37:02 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 10:25:21 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_list		*ft_new_list(void)
{
	t_list	*root;

	if ((root = (t_list *)malloc(sizeof(*root))) == NULL)
		exit(1);
	root->len = 0;
	root->val = 0;
	root->root = root;
	root->prev = root;
	root->next = root;
	return (root);
}

void		ft_before_list(t_list *elem, int val)
{
	t_list	*new_elem;

	if ((new_elem = (t_list *)malloc(sizeof(*new_elem))) == NULL)
		exit(1);
	new_elem->val = val;
	new_elem->prev = elem->prev;
	new_elem->next = elem;
	elem->prev->next = new_elem;
	elem->prev = new_elem;
	elem->root->len += 1;
}

void		ft_after_list(t_list *elem, int val)
{
	t_list	*new_elem;

	if ((new_elem = (t_list *)malloc(sizeof(*new_elem))) == NULL)
		exit(1);
	new_elem->val = val;
	new_elem->prev = elem;
	new_elem->next = elem->next;
	elem->next->prev = new_elem;
	elem->next = new_elem;
	elem->root->len += 1;
}

void		ft_head_list(t_list *root, int val)
{
	ft_after_list(root, val);
}

void		ft_tail_list(t_list *root, int val)
{
	ft_before_list(root, val);
}
