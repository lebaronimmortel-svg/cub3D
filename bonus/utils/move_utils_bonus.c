/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 09:34:22 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:29:47 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	forward(t_game *g, double ms)
{
	double	nx;
	double	ny;

	nx = g->player.pos_x + g->player.dir_x * ms;
	ny = g->player.pos_y + g->player.dir_y * ms;
	if (!is_wall(g, (int)nx, (int)g->player.pos_y)
		&& !is_door(g, (int)nx, (int)g->player.pos_y))
		g->player.pos_x = nx;
	if (!is_wall(g, (int)g->player.pos_x, (int)ny)
		&& !is_door(g, (int)g->player.pos_x, (int)ny))
		g->player.pos_y = ny;
}

void	backward(t_game *g, double ms)
{
	double	nx;
	double	ny;

	nx = g->player.pos_x - g->player.dir_x * ms;
	ny = g->player.pos_y - g->player.dir_y * ms;
	if (!is_wall(g, (int)nx, (int)g->player.pos_y)
		&& !is_door(g, (int)nx, (int)g->player.pos_y))
		g->player.pos_x = nx;
	if (!is_wall(g, (int)g->player.pos_x, (int)ny)
		&& !is_door(g, (int)g->player.pos_x, (int)ny))
		g->player.pos_y = ny;
}

void	left(t_game *g, double rs)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(-rs) - g->player.dir_y * sin(-rs);
	g->player.dir_y = old_dir_x * sin(-rs) + g->player.dir_y * cos(-rs);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(-rs) - g->player.plane_y
		* sin(-rs);
	g->player.plane_y = old_plane_x * sin(-rs) + g->player.plane_y
		* cos(-rs);
}

void	right(t_game *g, double rs)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(rs) - g->player.dir_y * sin(rs);
	g->player.dir_y = old_dir_x * sin(rs) + g->player.dir_y * cos(rs);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(rs) - g->player.plane_y
		* sin(rs);
	g->player.plane_y = old_plane_x * sin(rs) + g->player.plane_y * cos(rs);
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
	if (g->keys[4])
		straf_right(g, ms);
	if (g->keys[5])
		straf_left(g, ms);
}
