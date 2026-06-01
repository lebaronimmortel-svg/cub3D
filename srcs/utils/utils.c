/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:24:49 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/20 08:24:50 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static void	set_player_dir_vec(t_game *g, char c)
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

static void	set_player_plane(t_game *g, char c)
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

void	init_player_at(t_game *g, int x, int y, char c)
{
	g->player.pos_x = x + 0.5;
	g->player.pos_y = y + 0.5;
	set_player_dir_vec(g, c);
	set_player_plane(g, c);
	g->map.grid_map[y][x] = '0';
}
