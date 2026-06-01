/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:03 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H
# include "../../header/header.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_map
{
	char		**grid_map;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	t_color		floor;
	t_color		ceiling;
	mlx_image	tex[4];
	int			tex_w;
	int			tex_h;
}	t_map;

/*
** keys[0] = W      (move forward)
** keys[1] = S      (move backward)
** keys[2] = A      (rotate left)
** keys[3] = D      (rotate right)
** keys[4] = LEFT   (rotate left,  arrow)
** keys[5] = RIGHT  (rotate right, arrow)
*/

typedef struct s_game
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	mlx_image				img;
	t_player				player;
	t_map					map;
	int						keys[6];
	struct timeval			old_time;
}	t_game;

#endif
