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

int	main(void)
{
	t_game	g;

	init_player(&g);
	g.mlx = mlx_init();
	g.info = (mlx_window_create_info){0};
	g.info.title = "cub3D";
	g.info.width = 640;
	g.info.height = 480;
	g.win = mlx_new_window(g.mlx, &g.info);
	mlx_on_event(g.mlx, g.win, MLX_KEYDOWN, press_escp, g.mlx);
	mlx_loop(g.mlx);
	mlx_destroy_window(g.mlx, g.win);
	mlx_destroy_context(g.mlx);
	return (0);
}
