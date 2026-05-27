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

int	main_parser(int argc, char **argv)
{
	char	**map;
	int		error;

	error = 0;
	if (argc != 2)
		return (0);
	map = create_map(argv[1], &error);
	if (!map)
	{
		ft_putstr_fd("MAP NOT OK !\n", 1);
		return (0);
	}
	free_map(map);
	ft_putstr_fd("MAP OK !\n", 1);
	return (1);
}
