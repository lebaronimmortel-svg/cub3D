/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:41:45 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/03 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

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

static void	calc_slice(t_game *g, t_ray *r)
{
	if (r->side == 0)
		r->perp = r->sdist_x - r->ddist_x;
	else
		r->perp = r->sdist_y - r->ddist_y;
	r->lh = (int)((double)g->info.height / r->perp);
	r->ds = -r->lh / 2 + g->info.height / 2;
	if (r->ds < 0)
		r->ds = 0;
	r->de = r->lh / 2 + g->info.height / 2;
	if (r->de >= g->info.height)
		r->de = g->info.height - 1;
}

static void	calc_tex_x(t_game *g, t_ray *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = g->player.pos_y + r->perp * r->rdir_y;
	else
		wall_x = g->player.pos_x + r->perp * r->rdir_x;
	wall_x -= floor(wall_x);
	r->tex_x = (int)(wall_x * (double)g->map.tex_w);
	if (r->side == 0 && r->rdir_x > 0)
		r->tex_x = g->map.tex_w - r->tex_x - 1;
	if (r->side == 1 && r->rdir_y < 0)
		r->tex_x = g->map.tex_w - r->tex_x - 1;
	r->tex_step = (double)g->map.tex_h / (double)r->lh;
	r->tex_pos = ((double)r->ds - (double)g->info.height / 2.0
			+ (double)r->lh / 2.0) * r->tex_step;
}

void	cast_ray(t_game *g, int x)
{
	t_ray	r;

	init_ray(g, &r, x);
	init_dda(g, &r);
	dda_loop(g, &r);
	calc_slice(g, &r);
	calc_tex_x(g, &r);
	draw_col(g, &r, x);
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
