/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 14:47:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/06/26 14:10:38 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# define TRUE 1
# define FALSE 0

/*
** Lists and Stuctures
*/

typedef struct		s_infos
{
	int				ants;
	char			*start;
	char			*end;
	char			**tab;
	int				name;
	int				link;
}					t_infos;

typedef struct		s_lst
{
	int				data;
	int				tube;
	struct s_lst	*next;
}					t_lst;

/*
** Parsing
*/

t_infos				*parse_infos(void);
t_infos				*infos_alloc(void);
t_lst				*ft_create_elem(int data, int tube);

#endif
