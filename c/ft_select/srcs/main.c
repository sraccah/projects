/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:22:34 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/04 04:59:50 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

int					main(int ac, char **av)
{
	struct termios	term;
	t_list			*list;

	if (ac > 1)
	{
		list = NULL;
		ft_getinlist(&av[1], &list);
		if (ft_init_term(&term))
			return (ft_print_error("[ERROR] : Term couldn't be initialize"));
		if (ft_apply_term(&term))
			return (ft_print_error("[ERROR] : Term changes couldn't be done"));
		ft_press_key(list);
		if (ft_reset_term(&term))
			return (ft_print_error("[ERROR] : Term reset couldn't be done"));
	}
	return (0);
}
