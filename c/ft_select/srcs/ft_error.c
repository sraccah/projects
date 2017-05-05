/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 17:54:16 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/04 00:21:38 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_putendl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_print_error(char *error)
{
	write(2, "\033[0;31;1m", 9);
	write(2, error, ft_strlen((const char *)error));
	write(2, "\033[0m", 4);
	write(2, "\n", 1);
	return (-1);
}
