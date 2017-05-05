/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 10:02:48 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 10:18:29 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_after_clist(t_clist *elem, void *content)
{
	t_clist	*new_elem;

	if ((new_elem = (t_clist *)malloc(sizeof(*new_elem))) == NULL)
		exit(1);
	new_elem->content = content;
	new_elem->prev = elem;
	new_elem->next = elem->next;
	elem->next->prev = new_elem;
	elem->next = new_elem;
	elem->root->len += 1;
}
