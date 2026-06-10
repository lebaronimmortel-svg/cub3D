/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 08:40:54 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:27:53 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	free_map_info(t_game *g)
{
	if (g->map.no)
		free(g->map.no);
	if (g->map.so)
		free(g->map.so);
	if (g->map.we)
		free(g->map.we);
	if (g->map.ea)
		free(g->map.ea);
	g->map.no = NULL;
	g->map.so = NULL;
	g->map.we = NULL;
	g->map.ea = NULL;
}

static void	destroy_img(t_game *g)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (g->player.shot_anim[i])
			mlx_destroy_image(g->mlx, g->player.shot_anim[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (g->player.walk_anim[i])
			mlx_destroy_image(g->mlx, g->player.walk_anim[i]);
		i++;
	}
	if (g->player.idle)
		mlx_destroy_image(g->mlx, g->player.idle);
}

void	end_game(t_game *g, int flag)
{
	int	i;

	if (flag)
		mlx_destroy_image(g->mlx, g->img);
	i = 0;
	while (i < 6)
	{
		if (g->map.tex[i])
			mlx_destroy_image(g->mlx, g->map.tex[i]);
		i++;
	}
	destroy_img(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_context(g->mlx);
	free_game(g);
}

void	free_game(t_game *g)
{
	free_map(g->map.grid_map);
	if (g->map.no)
		free(g->map.no);
	if (g->map.so)
		free(g->map.so);
	if (g->map.we)
		free(g->map.we);
	if (g->map.ea)
		free(g->map.ea);
	g->map.no = NULL;
	g->map.so = NULL;
	g->map.we = NULL;
	g->map.ea = NULL;
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
