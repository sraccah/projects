/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:10:16 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/26 14:08:56 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_lst	*ft_getlink(t_infos *lem, char *line, t_lst *room)
{
	char		*tmp;

	tmp = ft_strdup(line);
	lem->tab = ft_strsplit(tmp, '-');
	lem->name = ft_atoi(lem->tab[0]);
	lem->link = ft_atoi(lem->tab[1]);
	ft_print_blue("Link detected");
	room = ft_create_elem(lem->name, lem->link);
	room = room->next;
	return (room);
}

static void		ft_getinf(t_infos *lem, char *line, int *i)
{
	t_lst		*room;

	room = NULL;
	if (*i == 2 && ft_is(line, ' '))
	{
		lem->start = line;
		*i = 4;
	}
	else if (*i == 3 && ft_is(line, ' '))
	{
		lem->end = line;
		*i = 4;
	}
	else if (*i == 4 && ft_is(line, '-'))
		room = ft_getlink(lem, line, room);
}

static void		ft_parsinf(t_infos *lem, char *line, int *i)
{
	if (*i == 0 && *line != '#' && *line != 'L')
	{
		lem->ants = ft_atoi(line);
		*i = 1;
	}
	else if (ft_strequ(line, "##start"))
		*i = 2;
	else if (ft_strequ(line, "##end"))
		*i = 3;
	else if (*line == '#' && *line == 'L')
		;
	else if (*i == 2 && ft_is(line, ' '))
		ft_getinf(lem, line, i);
	else if (*i == 3 && ft_is(line, ' '))
		ft_getinf(lem, line, i);
	else if (*i == 4 && ft_is(line, '-'))
		ft_getinf(lem, line, i);
}

t_infos			*parse_infos(void)
{
	int			i;
	char		*line;
	t_infos		*lem;

	i = 0;
	lem = infos_alloc();
	while (ft_get_next_line(0, &line) && ft_strlen(line))
	{
		ft_print_green(line);
		ft_parsinf(lem, line, &i);
	}
	return (lem);
}
