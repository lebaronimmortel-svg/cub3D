/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	init_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map.grid_map[y])
	{
		x = 0;
		while (g->map.grid_map[y][x])
		{
			if (g->map.grid_map[y][x] == 'N' || g->map.grid_map[y][x] == 'S'
				|| g->map.grid_map[y][x] == 'E'
				|| g->map.grid_map[y][x] == 'W')
			{
				g->player.pos_x = x + 0.5;
				g->player.pos_y = y + 0.5;
				if (g->map.grid_map[y][x] == 'N')
				{
					g->player.dir_x = 0.0;
					g->player.dir_y = -1.0;
					g->player.plane_x = 0.66;
					g->player.plane_y = 0.0;
				}
				else if (g->map.grid_map[y][x] == 'S')
				{
					g->player.dir_x = 0.0;
					g->player.dir_y = 1.0;
					g->player.plane_x = -0.66;
					g->player.plane_y = 0.0;
				}
				else if (g->map.grid_map[y][x] == 'E')
				{
					g->player.dir_x = 1.0;
					g->player.dir_y = 0.0;
					g->player.plane_x = 0.0;
					g->player.plane_y = 0.66;
				}
				else
				{
					g->player.dir_x = -1.0;
					g->player.dir_y = 0.0;
					g->player.plane_x = 0.0;
					g->player.plane_y = -0.66;
				}
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
	mlx_on_event(g->mlx, g->win, MLX_WINDOW_EVENT, press_cross, g->mlx);
	mlx_add_loop_hook(g->mlx, init_game, g);
	gettimeofday(&g->old_time, NULL);
}

int	init_img(t_game *g)
{
	int	one;
	int	two;
	int	three;
	int	four;
;
	one = open(g->map.EA, O_RDONLY);
	two = open(g->map.NO, O_RDONLY);
	three = open(g->map.WE, O_RDONLY);
	four = open(g->map.SO, O_RDONLY);
	if (one == -1 || two == -1 || three == -1 || four == -1)
	{
		close_img(one, two, three, four);
		printf("Error in the image files\n");
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
	update_move(g, ft);
	draw_scene(g);
}
