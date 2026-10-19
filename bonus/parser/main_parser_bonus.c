/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:45:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:46 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	set_texture(t_map *tm, char *path, int flag)
{
	if (flag == 2)
	{
		free(tm->no);
		tm->no = path;
	}
	else if (flag == 3)
	{
		free(tm->so);
		tm->so = path;
	}
	else if (flag == 4)
	{
		free(tm->we);
		tm->we = path;
	}
	else if (flag == 5)
	{
		free(tm->ea);
		tm->ea = path;
	}
}

static void	put_error_msg(int error)
{
	if (error == 0)
		ft_putstr_fd("IMPLICIT START POSITION\n", 1);
	else if (error == 1)
		ft_putstr_fd("BAD PERMISSIONS\n", 1);
	else if (error == 2)
		ft_putstr_fd("MAP FILE REQUIRED\n", 1);
	else if (error == 3)
		ft_putstr_fd("INVALID FILE NAME\n", 1);
	else if (error == 4)
		ft_putstr_fd("UNEXPECTED TOKEN\n", 1);
	else if (error == 5)
		ft_putstr_fd("UNCLOSED MAP\n", 1);
	else if (error == 6)
		ft_putstr_fd("INVALID INFO SYNTAX\n", 1);
	else if (error == 8)
		ft_putstr_fd("UNABLE TO OPEN FILE\n", 1);
	else if (error == 9)
		ft_putstr_fd("MEMORY ALLOCATION FAILED\n", 1);
}

static void	tex_init(t_game *g)
{
	int	i;

	g->map.grid_map = NULL;
	g->map.no = NULL;
	g->map.so = NULL;
	g->map.we = NULL;
	g->map.ea = NULL;
	g->map.floor = (t_color){0, 0, 0};
	g->map.ceiling = (t_color){0, 0, 0};
	g->map.tex[0] = NULL;
	g->map.tex[1] = NULL;
	g->map.tex[2] = NULL;
	g->map.tex[3] = NULL;
	g->map.tex[4] = NULL;
	g->map.tex[5] = NULL;
	g->map.tex_w = 0;
	g->map.tex_h = 0;
	g->player.idle = NULL;
	i = 0;
	while (i < 10)
		g->player.walk_anim[i++] = NULL;
	i = 0;
	while (i < 6)
		g->player.shot_anim[i++] = NULL;
}

int	main_parser(int argc, char **argv, t_game *g)
{
	int	error;
	int	i;

	tex_init(g);
	i = 0;
	while (i < 7)
		g->keys[i++] = 0;
	error = 7;
	if (argc != 2)
	{
		ft_putstr_fd("Error :\n", 1);
		put_error_msg(2);
		return (0);
	}
	g->map.grid_map = create_map(argv[1], &error, &g->map);
	if (!g->map.grid_map)
	{
		ft_putstr_fd("Error :\n", 1);
		put_error_msg(error);
		free_map_info(g);
		return (0);
	}
	return (1);
}
