/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static void	draw_cursor(t_game *g)
{
	mlx_color	white;
	int			y;
	int			x;
	int			y2;
	int			x2;

	white = rgb(255, 255, 255);
	y = 0;
	while (y < 11)
	{
		x = 0;
		while (x < 11)
		{
			if (y == 5 || x == 5)
			{
				y2 = 0;
				while (y2 < 4)
				{
					x2 = 0;
					while (x2 < 4)
					{
						mlx_set_image_pixel(g->mlx, g->img,
							300 + (x * 2 + x2),
							250 + (y * 2 + y2), white);
						x2++;
					}
					y2++;
				}
			}
			x++;
		}
		y++;
	}
}

void	display_hands(t_game *g)
{
	if ((!g->keys[0] && !g->keys[1]) || g->keys[6])
		draw_cursor(g);
	if (g->keys[6] == 1)
	{
		if (g->timer / 3 % 6 == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->shot_anim[0], -20, 120);
		else if (g->timer / 3 % 6 == 1)
			mlx_put_image_to_window(g->mlx, g->win, g->shot_anim[1], -20, 120);
		else if (g->timer / 3 % 6 == 2)
			mlx_put_image_to_window(g->mlx, g->win, g->shot_anim[2], -20, 120);
		else if (g->timer / 3 % 6 == 3)
			mlx_put_image_to_window(g->mlx, g->win, g->shot_anim[3], -20, 120);
		else if (g->timer / 3 % 6 == 4)
			mlx_put_image_to_window(g->mlx, g->win, g->shot_anim[4], -20, 120);
		else if (g->timer / 3 % 6 == 5)
			mlx_put_image_to_window(g->mlx, g->win, g->shot_anim[5], -20, 120);
	}
	else if (g->keys[0] == 0 && g->keys[1] == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->idle, 100, 200);
	else
	{
		if (g->timer / 5 % 10 == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[0], 100, 160);
		if (g->timer / 5 % 10 == 1)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[1], 100, 160);
		else if (g->timer / 5 % 10 == 2)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[2], 100, 160);
		else if (g->timer / 5 % 10 == 3)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[3], 100, 160);
		else if (g->timer / 5 % 10 == 4)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[4], 100, 160);
		else if (g->timer / 5 % 10 == 5)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[5], 100, 160);
		else if (g->timer / 5 % 10 == 6)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[6], 100, 160);
		else if (g->timer / 5 % 10 == 7)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[7], 100, 160);
		else if (g->timer / 5 % 10 == 8)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[8], 100, 160);
		else if (g->timer / 5 % 10 == 9)
			mlx_put_image_to_window(g->mlx, g->win, g->walk_anim[9], 100, 160);
	}
}
