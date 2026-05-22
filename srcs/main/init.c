/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/20 08:07:12 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	init_player(t_game *g)
{
	g->player.pos_x = 22.0;
	g->player.pos_y = 12.0;
	g->player.dir_x = -1.0;
	g->player.dir_y = 0.0;
	g->player.plane_x = 0.0;
	g->player.plane_y = 0.66;
}
