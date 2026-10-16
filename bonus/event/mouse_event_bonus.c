/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:38:16 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:27:45 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	mouse_up(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 1)
		g->keys[6] = 0;
}

void	mouse_down(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (key == 1)
		g->keys[6] = 1;
}
