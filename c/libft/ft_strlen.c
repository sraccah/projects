/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:20:21 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/20 14:41:16 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}
