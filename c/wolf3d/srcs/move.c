/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 16:00:00 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 10:36:38 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move_up(t_env *env)
{
	if (env->tab[(int)(env->pos_x + env->dir_x)][(int)(env->pos_y)] == 0)
		env->pos_x += env->dir_x;
	if (env->tab[(int)(env->pos_x)][(int)(env->pos_y + env->dir_y)] == 0)
		env->pos_y += env->dir_y;
}

void	ft_move_down(t_env *env)
{
	if (env->tab[(int)(env->pos_x - env->dir_x)][(int)(env->pos_y)] == 0)
		env->pos_x -= env->dir_x;
	if (env->tab[(int)(env->pos_x)][(int)(env->pos_y - env->dir_y)] == 0)
		env->pos_y -= env->dir_y;
}

void	ft_move_left(t_env *env)
{
	env->old_dir_x = env->dir_x;
	env->dir_x = env->dir_x * cos(-(0.175)) - env->dir_y * sin(-(0.175));
	env->dir_y = env->old_dir_x * sin(-(0.175)) + env->dir_y * cos(-(0.175));
	env->old_plane_x = env->plane_x;
	env->plane_x = env->plane_x * cos(-(0.175)) - env->plane_y * sin(-(0.175));
	env->plane_y = env->old_plane_x * sin(-(0.175))
	+ env->plane_y * cos(-(0.175));
}

void	ft_move_right(t_env *env)
{
	env->old_dir_x = env->dir_x;
	env->dir_x = env->dir_x * cos((0.175)) - env->dir_y * sin((0.175));
	env->dir_y = env->old_dir_x * sin((0.175)) + env->dir_y * cos((0.175));
	env->old_plane_x = env->plane_x;
	env->plane_x = env->plane_x * cos((0.175)) - env->plane_y * sin((0.175));
	env->plane_y = env->old_plane_x * sin((0.175))
	+ env->plane_y * cos((0.175));
}
