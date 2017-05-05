/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:52:29 by sraccah           #+#    #+#             */
/*   Updated: 2014/07/16 10:51:39 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t		ft_getcolor(t_env *env)
{
	size_t	color;

	color = 0;
	if (ft_checkhit(env) == '5')
	{
		if (env->side == 0.0)
			color = RGB_WALL_N;
		else if (env->side == 1.0)
			color = RGB_WALL_E;
		else if (env->side == 2.0)
			color = RGB_WALL_O;
		else if (env->side == 3.0)
			color = RGB_WALL_S;
	}
	else
		color = RGB_DOOR;
	return (color);
}

void		ft_draw(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCREEN_X)
	{
		j = 0;
		ft_init(env, i);
		ft_calcray(env);
		ft_checkhit(env);
		ft_calcdraw(env);
		while (j < env->draw_start)
			mlx_pixel_put(env->mlx, env->win, i, j++, RGB_SKY);
		while (env->draw_start <= env->draw_end)
		{
			mlx_pixel_put(env->mlx, env->win, i, env->draw_start,
			ft_getcolor(env));
			env->draw_start++;
			j++;
		}
		while (j < SCREEN_Y)
			mlx_pixel_put(env->mlx, env->win, i, j++, RGB_FLOOR);
		i++;
	}
}

int			ft_expose_hook(t_env *env)
{
	ft_draw(env);
	return (0);
}

int			ft_key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == W || keycode == UP)
		ft_move_up(env);
	if (keycode == S || keycode == DOWN)
		ft_move_down(env);
	if (keycode == A || keycode == LEFT)
		ft_move_left(env);
	if (keycode == D || keycode == RIGHT)
		ft_move_right(env);
	ft_draw(env);
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	t_env	env;

	if (envp[0] == NULL)
		exit(1);
	if (argc == 2)
	{
		env.ac = argc;
		env.av = argv;
		ft_nbr_line_col(&env);
		ft_stock_value(&env);
		ft_help();
		env.pos_x = 2;
		env.pos_y = 2;
		env.dir_x = 1;
		env.dir_y = 0;
		env.plane_x = 0;
		env.plane_y = 0.66;
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, SCREEN_X, SCREEN_Y, "Wolf3D");
		mlx_expose_hook(env.win, ft_expose_hook, &env);
		mlx_hook(env.win, 2, 1, ft_key_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
