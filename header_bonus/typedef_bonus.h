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
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		floor;
	t_color		ceiling;
	mlx_image	tex[4];
	int			tex_w;
	int			tex_h;
}	t_map;

/*
** keys[0] = W      	(move forward)
** keys[1] = S      	(move backward)
** keys[2] = A      	(rotate left)
** keys[3] = D      	(rotate right)
** keys[4] = LEFT   	(rotate left,  arrow)
** keys[5] = RIGHT  	(rotate right, arrow)
** keys[6] = MOUSE_LEFT (shoot)
*/

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
	mlx_image				idle;
	mlx_image				walk_anim[10];
	mlx_image				shot_anim[6];
	struct timeval			old_time;
}	t_game;

#endif
