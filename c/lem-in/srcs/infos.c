/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:08:07 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/26 14:09:06 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

t_infos			*infos_alloc(void)
{
	t_infos		*lem;

	if ((lem = (t_infos *)malloc(sizeof(t_infos))))
	{
		lem->ants = 0;
		lem->start = NULL;
		lem->end = NULL;
		lem->name = 0;
		lem->link = 0;
	}
	else
		return (NULL);
	return (lem);
}

t_lst			*ft_create_elem(int data, int tube)
{
	t_lst		*elem;

	elem = malloc(sizeof(t_list));
	if (elem != NULL)
	{
		elem->data = data;
		elem->tube = tube;
	}
	else
		return (elem);
	return (elem);
}
