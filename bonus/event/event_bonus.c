/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:38:16 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:27:22 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	draw_col(t_game *g, t_ray *r, int x, int hit)
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
			get_tex_color(g, r, tex_y, hit));
		py++;
	}
}
