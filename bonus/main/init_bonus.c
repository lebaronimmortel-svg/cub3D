/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	init_player(t_game *g)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (g->map.grid_map[y])
	{
		x = 0;
		while (g->map.grid_map[y][x])
		{
			c = g->map.grid_map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				g->player.pos_x = x + 0.5;
				g->player.pos_y = y + 0.5;
				set_player_dir_vec(g, c);
				set_player_plane(g, c);
				g->map.grid_map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	init_windows_mlx(t_game *g)
{
	g->mlx = mlx_init();
	g->info = (mlx_window_create_info){0};
	g->info.title = "cub3D";
	g->info.width = 640;
	g->info.height = 480;
	g->win = mlx_new_window(g->mlx, &g->info);
	g->img = mlx_new_image(g->mlx, g->info.width, g->info.height);
}

void	init_events(t_game *g)
{
	mlx_on_event(g->mlx, g->win, MLX_KEYDOWN, key_down, g);
	mlx_on_event(g->mlx, g->win, MLX_KEYUP, key_up, g);
	mlx_on_event(g->mlx, g->win, MLX_MOUSEUP, mouse_up, g);
	mlx_on_event(g->mlx, g->win, MLX_MOUSEDOWN, mouse_down, g);
	mlx_on_event(g->mlx, g->win, MLX_WINDOW_EVENT, press_cross, g->mlx);
	mlx_add_loop_hook(g->mlx, init_game, g);
	gettimeofday(&g->old_time, NULL);
	g->keys[6] = 0;
}

int	init_img(t_game *g)
{
	int	w;
	int	h;

	g->idle = mlx_new_image_from_file(g->mlx,
			"player_img/img.png", &w, &h);
	g->walk_anim[0] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_00.png", &w, &h);
	g->walk_anim[1] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_00,5.png", &w, &h);
	g->walk_anim[2] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_01.png", &w, &h);
	g->walk_anim[3] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_01,5.png", &w, &h);
	g->walk_anim[4] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_02.png", &w, &h);
	g->walk_anim[5] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_02,5.png", &w, &h);
	g->walk_anim[6] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_03.png", &w, &h);
	g->walk_anim[7] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_03,5.png", &w, &h);
	g->walk_anim[8] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_04.png", &w, &h);
	g->walk_anim[9] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_04,5.png", &w, &h);
	g->shot_anim[0] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_00.png", &w, &h);
	g->shot_anim[1] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_01.png", &w, &h);
	g->shot_anim[2] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_02.png", &w, &h);
	g->shot_anim[3] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_03.png", &w, &h);
	g->shot_anim[4] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_04.png", &w, &h);
	g->shot_anim[5] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_05.png", &w, &h);
	g->map.tex[0] = mlx_new_image_from_file(g->mlx, g->map.no, &w, &h);
	g->map.tex[1] = mlx_new_image_from_file(g->mlx, g->map.so, &w, &h);
	g->map.tex[2] = mlx_new_image_from_file(g->mlx, g->map.we, &w, &h);
	g->map.tex[3] = mlx_new_image_from_file(g->mlx, g->map.ea, &w, &h);
	g->map.tex[4] = mlx_new_image_from_file(g->mlx,
			"map/backroom/png/door.png", &w, &h);
	g->map.tex_w = w;
	g->map.tex_h = h;
	if (!g->idle || !g->map.tex[0] || !g->map.tex[1]
		|| !g->map.tex[2] || !g->map.tex[3])
	{
		ft_putstr_fd("Error\nIMAGES LOADING FAILED\n", 1);
		if (g->img)
			mlx_destroy_image(g->mlx, g->img);
		g->img = NULL;
		end_game(g);
		exit(1);
	}
	return (1);
}

void	init_game(void *ptr)
{
	t_game			*g;
	struct timeval	now;
	double			ft;

	g = (t_game *)ptr;
	gettimeofday(&now, NULL);
	ft = (now.tv_sec - g->old_time.tv_sec)
		+ (now.tv_usec - g->old_time.tv_usec) / 1e6;
	g->old_time = now;
	update_move(g, ft * 3.0, ft * 2.0);
	draw_scene(g);
}
