/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:03 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:30:41 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_BONUS_H
# define TYPEDEF_BONUS_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int			is_shooting;
	mlx_image	walk_anim[10];
	mlx_image	shot_anim[6];
	mlx_image	idle;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}	t_player;

typedef struct s_map
{
	char		**grid_map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		floor;
	t_color		ceiling;
	mlx_image	tex[6];
	int			tex_w;
	int			tex_h;
}	t_map;

typedef struct s_game
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	mlx_image				img;
	t_player				player;
	t_map					map;
	int						keys[7];
	int						timer;
	struct timeval			old_time;
}	t_game;

typedef struct s_ray
{
	double	rdir_x;
	double	rdir_y;
	int		map_x;
	int		map_y;
	double	sdist_x;
	double	sdist_y;
	double	ddist_x;
	double	ddist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	perp;
	int		lh;
	int		ds;
	int		de;
	int		tex_x;
	double	tex_step;
	double	tex_pos;
}	t_ray;

#endif
