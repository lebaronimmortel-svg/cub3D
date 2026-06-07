/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:24:49 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:30:52 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	set_player_dir_vec(t_game *g, char c)
{
	if (c == 'N')
	{
		g->player.dir_x = 0.0;
		g->player.dir_y = -1.0;
	}
	else if (c == 'S')
	{
		g->player.dir_x = 0.0;
		g->player.dir_y = 1.0;
	}
	else if (c == 'E')
	{
		g->player.dir_x = 1.0;
		g->player.dir_y = 0.0;
	}
	else if (c == 'W')
	{
		g->player.dir_x = -1.0;
		g->player.dir_y = 0.0;
	}
}

void	set_player_plane(t_game *g, char c)
{
	if (c == 'N')
	{
		g->player.plane_x = 0.66;
		g->player.plane_y = 0.0;
	}
	else if (c == 'S')
	{
		g->player.plane_x = -0.66;
		g->player.plane_y = 0.0;
	}
	else if (c == 'E')
	{
		g->player.plane_x = 0.0;
		g->player.plane_y = 0.66;
	}
	else if (c == 'W')
	{
		g->player.plane_x = 0.0;
		g->player.plane_y = -0.66;
	}
}

int	pick_tex(int side, int step_x, int step_y)
{
	if (side == 0)
	{
		if (step_x > 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (step_y > 0)
			return (1);
		else
			return (0);
	}
}

mlx_color	rgb(int r, int g, int b)
{
	mlx_color	c;

	c.r = (uint8_t)r;
	c.g = (uint8_t)g;
	c.b = (uint8_t)b;
	c.a = 255;
	return (c);
}

mlx_color	get_tex_color(t_game *g, t_ray *r, int tex_y, int hit)
{
	mlx_color	color;

	if (hit == 1)
	{
		color = mlx_get_image_pixel(g->mlx,
				g->map.tex[pick_tex(r->side,
					r->step_x, r->step_y)],
				r->tex_x, tex_y);
	}
	else if (hit == 2 || hit == 3)
	{
		color = mlx_get_image_pixel(g->mlx,
				g->map.tex[2 + hit],
				r->tex_x, tex_y);
	}
	if (r->side == 1)
	{
		color.r >>= 1;
		color.g >>= 1;
		color.b >>= 1;
	}
	return (color);
}
