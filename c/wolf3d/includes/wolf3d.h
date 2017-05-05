/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:02:25 by sraccah           #+#    #+#             */
/*   Updated: 2014/05/18 08:39:43 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define RGB_SKY 0x2DC9F0
# define RGB_FLOOR 0x0000FF
# define RGB_WALL_N 0x9EFD38
# define RGB_WALL_E 0xF7FF3C
# define RGB_WALL_O 0xFEA347
# define RGB_WALL_S 0xFF00FF
# define RGB_DOOR 0xB666D2
# define SCREEN_X 800.0
# define SCREEN_Y 600.0
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

/*
** Lists and Structures
*/

typedef struct 	s_env
{
	char		*line;
	char		**av;
	int			ac;
	int			fd;
	int			nbr_line;
	int			nbr_col;
	void		*win;
	void		*mlx;
	int			**tab;
	int     	map_x;
	int     	step_x;
	int     	step_y;
	int     	hit;
	int     	side;
	int     	line_h;
	int     	draw_start;
	int     	draw_end;
	int     	map_y;
	double  	ray_pos_x;
	double  	ray_pos_y;
	double  	ray_dir_x;
	double  	ray_dir_y;
	double  	side_dist_x;
	double  	side_dist_y;
	double  	delta_dist_x;
	double  	delta_dist_y;
	double  	wall_dist;
	double  	camera_x;
	double  	pos_x;
	double  	pos_y;
	double		end_x;
	double		end_y;
	double  	dir_x;
	double  	old_dir_x;
	double  	dir_y;
	double  	plane_x;
	double  	old_plane_x;
	double  	plane_y;
	double  	dist_x;
	double  	dist_y;
}				t_env;

/*
** move.c
*/

void    		ft_move_up(t_env *env);
void    		ft_move_down(t_env *env);
void    		ft_move_left(t_env *env);
void    		ft_move_right(t_env *env);

/*
** draw.c
*/

void            ft_init(t_env *env, int i);
int     		ft_checkhit(t_env *env);
void    		ft_calcray(t_env *env);
void    		ft_calcdraw(t_env *env);

/*
** init.c
*/
void			ft_help(void);
void    		ft_stock_value(t_env *env);
void    		ft_nbr_line_col(t_env *env);

#endif
