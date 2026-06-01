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

#include "../../header/header.h"

void	end_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_context(g->mlx);
	free_game(g);
}

void	free_game(t_game *g)
{
	if (g->map.grid_map)
		free_map(g->map.grid_map);
	if (g->map.NO)
		free(g->map.NO);
	if (g->map.SO)
		free(g->map.SO);
	if (g->map.WE)
		free(g->map.WE);
	if (g->map.EA)
		free(g->map.EA);
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