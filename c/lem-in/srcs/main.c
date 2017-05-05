/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/26 14:05:39 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print_infos(t_infos *lem)
{
	ft_print_yellow("GOOD !");
	ft_print_bnobs(ft_itoa(lem->ants));
	ft_print_red(" <- number of ants");
	ft_print_bnobs(lem->start);
	ft_print_red(" <- starting room");
	ft_print_bnobs(lem->end);
	ft_print_red(" <- ending room");
}

int				main(void)
{
	t_infos		*lem;

	lem = parse_infos();
	if (lem && lem->ants && lem->start && lem->end)
		ft_print_infos(lem);
	else if (lem && (!lem->ants || !lem->start || !lem->end))
	{
		if (lem && !lem->ants)
			ft_print_error("No 'ants' in your map");
		else if (lem && (!lem->start || !lem->end))
			ft_print_error("No 'start' or 'end' in your map");
	}
	else
		ft_print_error("The map isn't good bro ! Try another one ;)");
	return (0);
}
