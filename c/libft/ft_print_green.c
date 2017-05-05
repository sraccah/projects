/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_green.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:22:17 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 15:43:46 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_green(char *error)
{
	write(1, GREEN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, RESET, 4);
	write(1, "\n", 1);
}
