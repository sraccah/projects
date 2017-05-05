/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pnobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:24:41 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 15:44:02 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_pnobs(char *error)
{
	write(1, PURPLE, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, RESET, 4);
}
