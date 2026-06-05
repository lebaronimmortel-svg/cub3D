/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 08:40:54 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 08:40:56 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	end_game(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g->map.tex[i])
			mlx_destroy_image(g->mlx, g->map.tex[i]);
		g->map.tex[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (g->shot_anim[i])
			mlx_destroy_image(g->mlx, g->shot_anim[i]);
		g->shot_anim[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (g->walk_anim[i])
			mlx_destroy_image(g->mlx, g->walk_anim[i]);
		g->walk_anim[i] = NULL;
		i++;
	}
	if (g->idle)
		mlx_destroy_image(g->mlx, g->idle);
	g->idle = NULL;
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_context(g->mlx);
	free_game(g);
}

void	free_game(t_game *g)
{
	if (g->map.grid_map)
		free_map(g->map.grid_map);
	if (g->map.no)
		free(g->map.no);
	if (g->map.so)
		free(g->map.so);
	if (g->map.we)
		free(g->map.we);
	if (g->map.ea)
		free(g->map.ea);
}

void	close_img(int one, int two, int three, int four)
{
	if (one != -1)
		close(one);
	if (two != -1)
		close(two);
	if (three != -1)
		close(three);
	if (four != -1)
		close(four);
}
