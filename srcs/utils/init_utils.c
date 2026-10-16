/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:07:43 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/03 10:07:44 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	init_ray(t_game *g, t_ray *r, int x)
{
	double	cam_x;

	cam_x = 2.0 * x / (double)g->info.width - 1.0;
	r->rdir_x = g->player.dir_x + g->player.plane_x * cam_x;
	r->rdir_y = g->player.dir_y + g->player.plane_y * cam_x;
	r->map_x = (int)g->player.pos_x;
	r->map_y = (int)g->player.pos_y;
	if (r->rdir_x == 0.0)
		r->ddist_x = 1e30;
	else
		r->ddist_x = fabs(1.0 / r->rdir_x);
	if (r->rdir_y == 0.0)
		r->ddist_y = 1e30;
	else
		r->ddist_y = fabs(1.0 / r->rdir_y);
}

void	init_dda(t_game *g, t_ray *r)
{
	if (r->rdir_x < 0.0)
	{
		r->step_x = -1;
		r->sdist_x = (g->player.pos_x - r->map_x) * r->ddist_x;
	}
	else
	{
		r->step_x = 1;
		r->sdist_x = (r->map_x + 1.0 - g->player.pos_x) * r->ddist_x;
	}
	if (r->rdir_y < 0.0)
	{
		r->step_y = -1;
		r->sdist_y = (g->player.pos_y - r->map_y) * r->ddist_y;
	}
	else
	{
		r->step_y = 1;
		r->sdist_y = (r->map_y + 1.0 - g->player.pos_y) * r->ddist_y;
	}
}

void	dda_loop(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	r->side = 0;
	while (!hit)
	{
		if (r->sdist_x < r->sdist_y)
		{
			r->sdist_x += r->ddist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sdist_y += r->ddist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall(g, r->map_x, r->map_y))
			hit = 1;
	}
}

mlx_color	get_tex_color(t_game *g, t_ray *r, int tex_y)
{
	mlx_color	color;

	color = mlx_get_image_pixel(g->mlx,
			g->map.tex[pick_tex(r->side,
				r->step_x, r->step_y)],
			r->tex_x, tex_y);
	if (r->side == 1)
	{
		color.r >>= 1;
		color.g >>= 1;
		color.b >>= 1;
	}
	return (color);
}

void	draw_col(t_game *g, t_ray *r, int x)
{
	int	py;
	int	tex_y;

	py = r->ds;
	while (py <= r->de)
	{
		tex_y = (int)r->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= g->map.tex_h)
			tex_y = g->map.tex_h - 1;
		r->tex_pos += r->tex_step;
		mlx_set_image_pixel(g->mlx, g->img, x, py,
			get_tex_color(g, r, tex_y));
		py++;
	}
}
