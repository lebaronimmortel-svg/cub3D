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

int	is_wall(t_game *g, int wx, int wy)
{
	if (wy < 0 || wx < 0 || !g->map.grid_map[wy])
		return (1);
	if (!g->map.grid_map[wy][wx])
		return (1);
	return (g->map.grid_map[wy][wx] != '0');
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
