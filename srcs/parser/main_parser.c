/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:45:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/12 19:11:57 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	main_parser(int argc, char **argv, t_game *g)
{
	int	error;
	int	i;

	g->map.grid_map = NULL;
	g->map.NO = NULL;
	g->map.SO = NULL;
	g->map.WE = NULL;
	g->map.EA = NULL;
	g->map.floor = (t_color){0, 0, 0};
	g->map.ceiling = (t_color){0, 0, 0};
	i = 0;
	while (i < 6)
		g->keys[i++] = 0;
	error = 0;
	if (argc != 2)
		return (0);
	g->map.grid_map = create_map(argv[1], &error, &g->map);
	if (!g->map.grid_map)
	{
		ft_putstr_fd("MAP NOT OK !\n", 1);
		return (0);
	}
	ft_putstr_fd("MAP OK !\n", 1);
	return (1);
}
