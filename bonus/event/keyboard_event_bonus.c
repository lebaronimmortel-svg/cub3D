/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:38:16 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:27:32 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static int	key_to_index(int key)
{
	if (key == 26 || key == 82)
	{
		return (0);
	}
	if (key == 22 || key == 81)
		return (1);
	if (key == 4)
		return (4);
	if (key == 80)
		return (2);
	if (key == 7)
		return (5);
	if (key == 79)
		return (3);
	return (-1);
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
