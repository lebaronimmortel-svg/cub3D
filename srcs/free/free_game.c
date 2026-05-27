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
