/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_yellow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:23:05 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 15:44:37 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_yellow(char *error)
{
	write(1, YELLOW, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, RESET, 4);
	write(1, "\n", 1);
}
