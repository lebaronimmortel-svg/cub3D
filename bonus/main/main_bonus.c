/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:07:11 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:19 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static void	mark_square(char **map, int i, int j)
{
	if (map[i][j - 1] == '1' && map[i][j + 1] == '1'
		&& map[i - 1][j] == '0' && map[i + 1][j] == '0')
		map[i][j] = 'D';
	else if (map[i - 1][j] == '1' && map[i + 1][j] == '1'
		&& map[i][j - 1] == '0' && map[i][j + 1] == '0')
		map[i][j] = 'D';
}

static void	mark_doors(t_game *g)
{
	int		i;
	int		j;
	char	**map;

	if (!g)
		return ;
	map = g->map.grid_map;
	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == '0')
				mark_square(map, i, j);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (!main_parser(argc, argv, &g))
		return (1);
	init_player(&g);
	init_windows_mlx(&g);
	init_events(&g);
	if (!init_img(&g))
	{
		ft_putstr_fd("Error\nIMAGES LOADING FAILED\n", 1);
		end_game(&g, 1);
		exit(1);
	}
	init_game(&g);
	mark_doors(&g);
	mlx_loop(g.mlx);
	if (g.img)
		mlx_destroy_image(g.mlx, g.img);
	end_game(&g, 0);
	return (0);
}
