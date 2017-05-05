/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:07:21 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/17 09:30:11 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int				main(int ac, char **av)
{
	t_list		*l_a;
	t_list		*l_b;
	int			i;

	if (ac < 2)
		ft_print_error("Error");
	i = 1;
	l_a = ft_new_list();
	l_b = ft_new_list();
	while (av[i])
		ft_tail_list(l_a, ft_atoi(av[i++]));
	if (ac == 2)
	{
		ft_print_error("Not enough numbers to do my job");
		ft_print_list_ps(l_a);
	}
	else if (ac > 2)
		ft_sort_list(l_a, l_b);
	ft_del_list(&l_a);
	ft_del_list(&l_b);
	return (0);
}
