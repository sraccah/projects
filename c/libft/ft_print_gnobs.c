/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_gnobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:24:10 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 15:43:52 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_gnobs(char *error)
{
	write(1, GREEN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, RESET, 4);
}
