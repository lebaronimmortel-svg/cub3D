/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:26:41 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static void	put_white_pixel(t_game *g, int *coord)
{
	mlx_color	white;

	white = rgb(255, 255, 255);
	mlx_set_image_pixel(g->mlx, g->img, 300 + (coord[1] * 2 + coord[3]++),
		250 + (coord[0] * 2 + coord[2]), white);
}

static void	draw_cursor(t_game *g)
{
	int			coord[4];

	coord[0] = 0;
	while (coord[0] < 11)
	{
		coord[1] = 0;
		while (coord[1] < 11)
		{
			if (coord[0] == 5 || coord[1] == 5)
			{
				coord[2] = 0;
				while (coord[2] < 4)
				{
					coord[3] = 0;
					while (coord[3] < 4)
						put_white_pixel(g, coord);
					coord[2]++;
				}
			}
			coord[1]++;
		}
		coord[0]++;
	}
}

static void	put_shot_frame(t_game *g)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (g->timer / 3 % 6 == i)
		{
			mlx_put_image_to_window
				(g->mlx, g->win, g->player.shot_anim[i], -20, 120);
			return ;
		}
		i++;
	}
}

static void	put_walk_frame(t_game *g)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (g->timer / 5 % 10 == i)
		{
			mlx_put_image_to_window
				(g->mlx, g->win, g->player.walk_anim[i], 100, 160);
			return ;
		}
		i++;
	}
}

void	display_hands(t_game *g)
{
	if ((!g->keys[0] && !g->keys[1]) || g->keys[6])
		draw_cursor(g);
	if (!g->keys[6])
		g->player.is_shooting = 0;
	if (g->keys[6] == 1)
		put_shot_frame(g);
	else if (g->keys[0] == 0 && g->keys[1] == 0)
		mlx_put_image_to_window
			(g->mlx, g->win, g->player.idle, 100, 200);
	else
		put_walk_frame(g);
}
