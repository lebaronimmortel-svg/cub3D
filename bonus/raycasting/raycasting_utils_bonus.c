/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:07:43 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:29:42 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

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
	r->side = 0;
}
