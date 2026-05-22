/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/20 08:07:12 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	init_player(t_game *g)
{
	g->player.pos_x = 22.0;
	g->player.pos_y = 12.0;
	g->player.dir_x = -1.0;
	g->player.dir_y = 0.0;
	g->player.plane_x = 0.0;
	g->player.plane_y = 0.66;
}

void	init_windows_mlx(t_game *g)
{
	g->mlx = mlx_init();
	g->info = (mlx_window_create_info){0};
	g->info.title = "cub3D";
	g->info.width = 640;
	g->info.height = 480;
	g->win = mlx_new_window(g->mlx, &g->info);
}

void	init_events(t_game *g)
{
	mlx_on_event(g->mlx, g->win, MLX_KEYDOWN, press_escp, g->mlx);
	mlx_on_event(g->mlx, g->win, MLX_WINDOW_EVENT, press_cross, g->mlx);
	mlx_add_loop_hook(g->mlx, init_game, g);
}

void	init_game(void *ptr)
{
	t_game	*g;
	int		x;

	g = (t_game*)ptr;
	x = 0;
	while (x < g->info.width)
	{
		ray_pos_dir(g);
		x++;
	}
}
