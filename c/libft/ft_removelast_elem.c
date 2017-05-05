/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removelast_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 09:59:02 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 09:59:18 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_removelast_elem(t_clist *list)
{
	if (list->prev != list)
	{
		list->len--;
		ft_remove_elem(list->prev);
	}
}
