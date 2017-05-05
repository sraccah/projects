/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 09:56:19 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 09:56:41 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_free_elem(t_clist *list)
{
	t_clist	*tmp;
	t_clist	*next_elem;

	tmp = list->next;
	while (tmp != list)
	{
		next_elem = tmp->next;
		free(tmp);
		tmp = next_elem;
	}
}
