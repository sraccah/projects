/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:40:45 by sraccah           #+#    #+#             */
/*   Updated: 2016/03/22 15:48:05 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] && i < maxlen)
			i++;
	return (i);
}
