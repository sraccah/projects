/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 15:22:56 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 10:41:23 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_init(t_env *env, int i)
{
	env->camera_x = 2 * i / (double)SCREEN_X - 1;
	env->ray_pos_x = env->pos_x;
	env->ray_pos_y = env->pos_y;
	env->ray_dir_x = env->dir_x + env->plane_x * env->camera_x;
	env->ray_dir_y = env->dir_y + env->plane_y * env->camera_x;
	env->map_x = (int)env->ray_pos_x;
	env->map_y = (int)env->ray_pos_y;
	env->delta_dist_x = sqrt(1 + (env->ray_dir_y * env->ray_dir_y)
	/ (env->ray_dir_x * env->ray_dir_x));
	env->delta_dist_y = sqrt(1 + (env->ray_dir_x * env->ray_dir_x)
	/ (env->ray_dir_y * env->ray_dir_y));
	env->hit = 0;
}

int				ft_checkhit(t_env *env)
{
	while (!env->hit)
	{
		if (env->side_dist_x < env->side_dist_y)
		{
			env->side_dist_x += env->delta_dist_x;
			env->map_x += env->step_x;
			if (env->ray_dir_x > 0)
				env->side = 0.0;
			else
				env->side = 1.0;
		}
		else
		{
			env->side_dist_y += env->delta_dist_y;
			env->map_y += env->step_y;
			if (env->ray_dir_y < 0)
				env->side = 2.0;
			else
				env->side = 3.0;
		}
		if (env->tab[env->map_x][env->map_y] > 0)
			env->hit = 1;
	}
	return (env->tab[env->map_x][env->map_y] + 48);
}

void			ft_calcray(t_env *env)
{
	if (env->ray_dir_x < 0)
	{
		env->step_x = -1;
		env->side_dist_x = (env->ray_pos_x - env->map_x) * env->delta_dist_x;
	}
	else
	{
		env->step_x = 1;
		env->side_dist_x = (env->map_x + 1.0 - env->ray_pos_x)
		* env->delta_dist_x;
	}
	if (env->ray_dir_y < 0)
	{
		env->step_y = -1;
		env->side_dist_y = (env->ray_pos_y - env->map_y) * env->delta_dist_y;
	}
	else
	{
		env->step_y = 1;
		env->side_dist_y = (env->map_y + 1.0 - env->ray_pos_y)
		* env->delta_dist_y;
	}
}

void			ft_calcdraw(t_env *env)
{
	if (env->side < 2.0)
		env->wall_dist = fabs((env->map_x - env->ray_pos_x
		+ (1 - env->step_x) / 2) / env->ray_dir_x);
	else
		env->wall_dist = fabs((env->map_y - env->ray_pos_y
		+ (1 - env->step_y) / 2) / env->ray_dir_y);
	env->line_h = abs((int)(SCREEN_Y / env->wall_dist));
	env->draw_start = -(env->line_h) / 2 + SCREEN_Y / 2;
	env->draw_end = env->line_h / 2 + SCREEN_Y / 2;
	if (env->draw_start < 0)
		env->draw_start = 0;
	if (env->draw_end >= SCREEN_Y)
		env->draw_end = SCREEN_Y - 1;
}
