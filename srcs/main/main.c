/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/20 08:07:12 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (!main_parser(argc, argv))
		return (1);
	init_player(&g);
	init_windows_mlx(&g);
	init_events(&g);
	init_game(&g);
	mlx_loop(g.mlx);
	mlx_destroy_window(g.mlx, g.win);
	mlx_destroy_context(g.mlx);
	return (0);
}
