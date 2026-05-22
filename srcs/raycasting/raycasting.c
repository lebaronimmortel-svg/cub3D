/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:41:45 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/22 09:41:48 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	ray_pos_dir(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->info.width)
	{
		g->player.camera_x = 2 * i / (double)(g->info.width) - 1;
		g->player.raydir_x = g->player.dir_x + g->player.plane_x * g->player.camera_x;
		g->player.raydir_y = g->player.dir_y + g->player.plane_y * g->player.camera_x;
		i++;
	}
}

void	grid(t_game *g)
{
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;

	mapx = (int)g->player.pos_x;
	mapy = (int)g->player.pos_y;
	if (g->player.raydir_x == 0.0)
		deltadistx = 1e30;
	else
		deltadistx = fabs(1.0 / g->player.raydir_x);
	if (g->player.raydir_y == 0.0)
		deltadisty = 1e30;
	else
		deltadisty = fabs(1.0 / g->player.raydir_y);
	hit = 0;
}
