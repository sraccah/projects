/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removefirst_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 09:58:22 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 09:58:38 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_removefirst_elem(t_clist *list)
{
	if (list->next != list)
	{
		list->len--;
		ft_remove_elem(list->next);
	}
}
