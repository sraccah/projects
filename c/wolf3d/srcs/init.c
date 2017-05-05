/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:00:04 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 11:51:10 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_help(void)
{
	ft_print_red("Welcome in my humble 'Wolf3D'");
	ft_print_red("in it...you can move with 'arrow keys' and 'wasd'");
	ft_print_red("and......that's pretty much it xD");
	ft_print_pnobs("PLEASE ! Do NOT lunch with a map without end empty line");
	ft_print_purple(", my ft_get_next_line do not understand it....thx");
	ft_print_green("And thx for correcting me btw ;)");
}

void		ft_stock_value(t_env *env)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env->tab = (int **)malloc(sizeof(int *) * (env->nbr_line + 1));
	env->tab[env->nbr_line] = '\0';
	while (i < env->nbr_line)
	{
		env->tab[i] = (int *)malloc(sizeof(int) * (env->nbr_col + 1));
		env->tab[i][env->nbr_col] = '\0';
		i++;
	}
	env->fd = open(env->av[1], O_RDONLY);
	while (ft_get_next_line(env->fd, &env->line))
	{
		i = 0;
		tmp = ft_strsplit(env->line, ' ');
		while (i++ < env->nbr_col)
			env->tab[j][i - 1] = ft_atoi(tmp[i - 1]);
		j++;
	}
}

void		ft_nbr_line_col(t_env *env)
{
	int		i;
	char	**tmp;

	env->nbr_line = 0;
	env->nbr_col = 0;
	if (!ft_strequ(env->av[1], "maps/map1.w3d")
	&& !ft_strequ(env->av[1], "maps/map2.w3d")
	&& !ft_strequ(env->av[1], "maps/map3.w3d"))
	{
		ft_print_error("Usage: ./wolf3d maps/exemple.w3d");
		exit(1);
	}
	env->fd = open(env->av[1], O_RDONLY);
	while (ft_get_next_line(env->fd, &env->line))
	{
		i = 0;
		tmp = ft_strsplit(env->line, ' ');
		ft_print_bnobs(env->line);
		ft_putchar('\n');
		while (tmp[i])
			i++;
		env->nbr_line++;
	}
	env->nbr_col = i;
}
