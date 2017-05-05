/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bnobs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 19:23:53 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 15:45:16 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_print_bnobs(char *error)
{
	write(1, CYAN, 7);
	write(1, error, ft_strlen((const char *)error));
	write(1, RESET, 4);
}
