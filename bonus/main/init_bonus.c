/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:05 by lukrodri         ###   ########.fr       */
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

int	init_windows_mlx(t_game *g)
{
	g->mlx = mlx_init();
	g->info = (mlx_window_create_info){0};
	g->info.title = "cub3D";
	g->info.width = 640;
	g->info.height = 480;
	g->player.is_shooting = 0;
	g->timer = 0;
	g->win = mlx_new_window(g->mlx, &g->info);
	if (!g->win)
		return (0);
	g->img = mlx_new_image(g->mlx, g->info.width, g->info.height);
	if (!g->img)
		return (0);
	return (1);
}

void	mouse_handler(t_game *g)
{
	int	x;
	int	y;
	int	cx;
	int	dx;

	cx = g->info.width / 2;
	mlx_mouse_get_pos(g->mlx, &x, &y);
	dx = (double)(x - cx);
	if (dx > 0.5)
		right(g, dx * 0.0025);
	else if (dx < -0.5)
		left(g, -dx * 0.0025);
	mlx_mouse_move(g->mlx, g->win, cx, g->info.height / 2);
}

void	init_events(t_game *g)
{
	mlx_on_event(g->mlx, g->win, MLX_KEYDOWN, key_down, g);
	mlx_on_event(g->mlx, g->win, MLX_KEYUP, key_up, g);
	mlx_on_event(g->mlx, g->win, MLX_MOUSEUP, mouse_up, g);
	mlx_on_event(g->mlx, g->win, MLX_MOUSEDOWN, mouse_down, g);
	mlx_on_event(g->mlx, g->win, MLX_WINDOW_EVENT, press_cross, g->mlx);
	mlx_add_loop_hook(g->mlx, init_game, g);
	mlx_mouse_hide(g->mlx);
	gettimeofday(&g->old_time, NULL);
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
	mouse_handler(g);
	update_move(g, ft * 3.0, ft * 2.0);
	draw_scene(g);
}
