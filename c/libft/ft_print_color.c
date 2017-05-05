/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 09:47:14 by sraccah           #+#    #+#             */
/*   Updated: 2016/06/02 09:47:25 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_print_color(char *color, char *option, char *error, int bs)
{
	if (color && option && error)
	{
		write(1, color, ft_strlen((const char *)color));
		write(1, option, ft_strlen((const char *)option));
		write(1, error, ft_strlen((const char *)error));
		write(1, RESET, 4);
		if (bs)
			write(1, "\n", 1);
	}
}
