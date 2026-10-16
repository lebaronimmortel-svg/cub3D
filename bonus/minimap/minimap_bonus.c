/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 06:57:18 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:26 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static void	fill_cell(t_game *g, int px, int py, mlx_color col)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < 5)
	{
		dx = 0;
		while (dx < 5)
		{
			if (px + dx >= 0 && px + dx < g->info.width
				&& py + dy >= 0 && py + dy < g->info.height)
				mlx_set_image_pixel(g->mlx, g->img,
					px + dx, py + dy, col);
			dx++;
		}
		dy++;
	}
}

static mlx_color	cell_color(char c)
{
	if (c == '1')
		return (rgb(180, 180, 180));
	if (c == '0')
		return (rgb(40, 40, 40));
	if (c == 'D')
		return (rgb(160, 100, 40));
	return (rgb(10, 10, 10));
}

static void	draw_cells(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map.grid_map[y])
	{
		x = 0;
		while (g->map.grid_map[y][x])
		{
			if (g->map.grid_map[y][x] != 32)
			{
				fill_cell(g,
					10 + x * 5,
					10 + y * 5,
					cell_color(g->map.grid_map[y][x]));
			}
			x++;
		}
		y++;
	}
}

static void	draw_player(t_game *g)
{
	mlx_color	col;
	int			px;
	int			py;
	int			d;

	col = rgb(220, 50, 50);
	px = 10 + (int)(g->player.pos_x * 5);
	py = 10 + (int)(g->player.pos_y * 5);
	d = -2;
	while (d <= 2)
	{
		if (px + d >= 0 && px + d < g->info.width)
			mlx_set_image_pixel(g->mlx, g->img, px + d, py, col);
		if (py + d >= 0 && py + d < g->info.height)
			mlx_set_image_pixel(g->mlx, g->img, px, py + d, col);
		d++;
	}
}

void	draw_minimap(t_game *g)
{
	draw_cells(g);
	draw_player(g);
}
