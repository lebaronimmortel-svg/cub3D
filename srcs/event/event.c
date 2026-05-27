/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:38:16 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

/*
** SDL scancodes used:
**   41  ESC
**   26  W       -> keys[0]  move forward
**   22  S       -> keys[1]  move backward
**    4  A       -> keys[2]  rotate left
**    7  D       -> keys[3]  rotate right
**   82  UP      -> keys[0]  (same as W)
**   81  DOWN    -> keys[1]  (same as S)
**   80  LEFT    -> keys[2]  (same as A)
**   79  RIGHT   -> keys[3]  (same as D)
*/

static int	key_to_index(int key)
{
	if (key == 26 || key == 82)
	{
		return (0);
	}
		if (key == 22 || key == 81)
		return (1);
	if (key == 4 || key == 80)
		return (2);
	if (key == 7 || key == 79)
		return (3);
	return (-1);
}

void	key_down(int key, void *param)
{
	t_game	*g;
	int		idx;

	g = (t_game *)param;
	if (key == 41)
		mlx_loop_end(g->mlx);
	idx = key_to_index(key);
	if (idx >= 0)
		g->keys[idx] = 1;
}

void	key_up(int key, void *param)
{
	t_game	*g;
	int		idx;

	g = (t_game *)param;
	idx = key_to_index(key);
	if (idx >= 0)
		g->keys[idx] = 0;
}

void	press_escp(int key, void *param)
{
	(void)param;
	(void)key;
}

void	press_cross(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}
