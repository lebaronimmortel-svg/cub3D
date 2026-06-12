/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:07:43 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:29:42 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

int	is_door(t_game *g, int i, int j)
{
	char	**map;

	map = g->map.grid_map;
	if (!g || !map || j >= my_memlen(map))
		return (0);
	if (i >= (int)ft_strlen(map[j]))
		return (0);
	if (map[j][i] == 'D')
		return (1);
	return (0);
}

static int	is_open_door(t_game *g, int i, int j)
{
	char	**map;

	map = g->map.grid_map;
	if (!g || !map || j >= my_memlen(map))
		return (0);
	if (i >= (int)ft_strlen(map[j]))
		return (0);
	if (map[j][i] == 'A')
		return (1);
	return (0);
}

static int	faces_a_door(t_game *g, t_ray *ray)
{
	double	dir_x;
	double	dir_y;
	double	to_bloc_x;
	double	to_bloc_y;
	double	norm;

	dir_x = g->player.dir_x;
	dir_y = g->player.dir_y;
	to_bloc_x = (ray->map_x + 0.5) - g->player.pos_x;
	to_bloc_y = (ray->map_y + 0.5) - g->player.pos_y;
	norm = sqrt(to_bloc_x * to_bloc_x + to_bloc_y * to_bloc_y);
	if (norm == 0)
		return (0);
	to_bloc_x /= norm;
	to_bloc_y /= norm;
	if ((dir_x * to_bloc_x) + (dir_y * to_bloc_y) > 0.97)
		return (1);
	return (0);
}

static int	update_door_state(int hit, t_game *g, t_ray *r)
{
	if (hit == 2 && g->keys[6] && g->player.is_shooting == 0)
	{
		if (faces_a_door(g, r))
		{
			g->player.is_shooting = 1;
			g->map.grid_map[r->map_y][r->map_x] = 'A';
			hit = 3;
		}
	}
	else if (hit == 3 && g->keys[6] && g->player.is_shooting == 0)
	{
		if (faces_a_door(g, r))
		{
			g->player.is_shooting = 1;
			g->map.grid_map[r->map_y][r->map_x] = 'D';
			hit = 2;
		}
	}
	return (hit);
}

int	dda_loop(t_game *g, t_ray *r, int x)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->sdist_x < r->sdist_y)
			update_ray(0, r);
		else
			update_ray(1, r);
		if (is_wall(g, r->map_x, r->map_y))
			hit = 1;
		else if (is_door(g, r->map_x, r->map_y))
			hit = 2;
		else if (is_open_door(g, r->map_x, r->map_y))
			hit = 3;
	}
	if (x == g->info.width / 2)
		return (update_door_state(hit, g, r));
	return (hit);
}
