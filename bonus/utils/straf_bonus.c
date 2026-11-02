/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straf_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 08:15:07 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/22 08:15:08 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	straf_left(t_game *g, double ms)
{
	double	nx;
	double	ny;

	nx = g->player.pos_x + g->player.plane_x * ms;
	ny = g->player.pos_y + g->player.plane_y * ms;
	if (!is_wall(g, (int)nx, (int)g->player.pos_y)
		&& !is_door(g, (int)nx, (int)g->player.pos_y))
		g->player.pos_x = nx;
	if (!is_wall(g, (int)g->player.pos_x, (int)ny)
		&& !is_door(g, (int)g->player.pos_x, (int)ny))
		g->player.pos_y = ny;
}

void	straf_right(t_game *g, double ms)
{
	double	nx;
	double	ny;

	nx = g->player.pos_x - g->player.plane_x * ms;
	ny = g->player.pos_y - g->player.plane_y * ms;
	if (!is_wall(g, (int)nx, (int)g->player.pos_y)
		&& !is_door(g, (int)nx, (int)g->player.pos_y))
		g->player.pos_x = nx;
	if (!is_wall(g, (int)g->player.pos_x, (int)ny)
		&& !is_door(g, (int)g->player.pos_x, (int)ny))
		g->player.pos_y = ny;
}
