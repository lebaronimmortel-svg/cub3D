/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:41:45 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static mlx_color	rgb(int r, int g, int b)
{
	mlx_color	c;

	c.r = (uint8_t)r;
	c.g = (uint8_t)g;
	c.b = (uint8_t)b;
	c.a = 255;
	return (c);
}

void	draw_floor_ceiling(t_game *g)
{
	mlx_color	ceil_c;
	mlx_color	floor_c;
	int			x;
	int			y;

	ceil_c = rgb(g->map.ceiling.r, g->map.ceiling.g, g->map.ceiling.b);
	floor_c = rgb(g->map.floor.r, g->map.floor.g, g->map.floor.b);
	y = 0;
	while (y < g->info.height)
	{
		x = 0;
		while (x < g->info.width)
		{
			if (y < g->info.height / 2)
				mlx_set_image_pixel(g->mlx, g->img, x, y, ceil_c);
			else
				mlx_set_image_pixel(g->mlx, g->img, x, y, floor_c);
			x++;
		}
		y++;
	}
}

void	cast_ray(t_game *g, int x)
{
	double		cam_x;
	double		rdir_x;
	double		rdir_y;
	int			map_x;
	int			map_y;
	double		sdist_x;
	double		sdist_y;
	double		ddist_x;
	double		ddist_y;
	double		perp;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lh;
	int			ds;
	int			de;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_step;
	double		tex_pos;
	mlx_color	color;
	int			py;

	cam_x = 2.0 * x / (double)g->info.width - 1.0;
	rdir_x = g->player.dir_x + g->player.plane_x * cam_x;
	rdir_y = g->player.dir_y + g->player.plane_y * cam_x;
	map_x = (int)g->player.pos_x;
	map_y = (int)g->player.pos_y;
	if (rdir_x == 0.0)
		ddist_x = 1e30;
	else
		ddist_x = fabs(1.0 / rdir_x);
	if (rdir_y == 0.0)
		ddist_y = 1e30;
	else
		ddist_y = fabs(1.0 / rdir_y);
	if (rdir_x < 0.0)
	{
		step_x = -1;
		sdist_x = (g->player.pos_x - map_x) * ddist_x;
	}
	else
	{
		step_x = 1;
		sdist_x = (map_x + 1.0 - g->player.pos_x) * ddist_x;
	}
	if (rdir_y < 0.0)
	{
		step_y = -1;
		sdist_y = (g->player.pos_y - map_y) * ddist_y;
	}
	else
	{
		step_y = 1;
		sdist_y = (map_y + 1.0 - g->player.pos_y) * ddist_y;
	}
	hit = 0;
	side = 0;
	while (!hit)
	{
		if (sdist_x < sdist_y)
		{
			sdist_x += ddist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			sdist_y += ddist_y;
			map_y += step_y;
			side = 1;
		}
		if (is_wall(g, map_x, map_y))
			hit = 1;
	}
	if (side == 0)
		perp = sdist_x - ddist_x;
	else
		perp = sdist_y - ddist_y;
	lh = (int)((double)g->info.height / perp);
	ds = -lh / 2 + g->info.height / 2;
	if (ds < 0)
		ds = 0;
	de = lh / 2 + g->info.height / 2;
	if (de >= g->info.height)
		de = g->info.height - 1;
	if (side == 0)
		wall_x = g->player.pos_y + perp * rdir_y;
	else
		wall_x = g->player.pos_x + perp * rdir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)g->map.tex_w);
	if (side == 0 && rdir_x > 0)
		tex_x = g->map.tex_w - tex_x - 1;
	if (side == 1 && rdir_y < 0)
		tex_x = g->map.tex_w - tex_x - 1;
	tex_step = (double)g->map.tex_h / (double)lh;
	tex_pos = ((double)ds - (double)g->info.height / 2.0
			+ (double)lh / 2.0) * tex_step;
	py = ds;
	while (py <= de)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= g->map.tex_h)
			tex_y = g->map.tex_h - 1;
		tex_pos += tex_step;
		color = mlx_get_image_pixel(g->mlx,
				g->map.tex[pick_tex(side, step_x, step_y)], tex_x, tex_y);
		if (side == 1)
		{
			color.r >>= 1;
			color.g >>= 1;
			color.b >>= 1;
		}
		mlx_set_image_pixel(g->mlx, g->img, x, py, color);
		py++;
	}
}

void	draw_scene(t_game *g)
{
	int	x;

	if (g->img)
		mlx_destroy_image(g->mlx, g->img);
	g->img = NULL;
	g->img = mlx_new_image(g->mlx, g->info.width, g->info.height);
	if (!g->img)
	{
		mlx_loop_end(g->mlx);
		return ;
	}
	draw_floor_ceiling(g);
	x = 0;
	while (x < g->info.width)
	{
		cast_ray(g, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}

void	update_move(t_game *g, double ms, double rs)
{
	if (g->keys[0])
		forward(g, ms);
	if (g->keys[1])
		backward(g, ms);
	if (g->keys[2])
		left(g, rs);
	if (g->keys[3])
		right(g, rs);
}
