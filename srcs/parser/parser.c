/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:48:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:42 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	check_count(int cnt, int *error)
{
	if (cnt != 1)
	{
		*error = 0;
		return (0);
	}
	return (1);
}

static int	skip_first_spaces(char **map, int *i, t_map *tm, int *error)
{
	if (!check_infos(map, i, tm))
	{
		*error = 6;
		return (0);
	}
	while (is_space(map[*i]))
		(*i)++;
	if (!is_suround_diff(&map[*i]))
	{
		*error = 5;
		return (0);
	}
	return (1);
}

int	is_valid_line(int *error, char **map, int i, int *cnt)
{
	if (!is_valid_middle_line(map[i], cnt, error))
		return (0);
	if (!check_enclosure(error, map, i))
		return (0);
	return (1);
}

int	item_count(char **map, int *error, int *start, t_map *tm)
{
	int	i;
	int	cnt;
	int	flag;

	if (!map || !(*map))
		return (0);
	i = 0;
	cnt = 0;
	if (!skip_first_spaces(map, &i, tm, error))
		return (0);
	*start = i;
	if (!is_valid_border_line(map[i], error, map[i + 1]))
		return (0);
	i++;
	flag = 0;
	while (map[i] && !is_space(map[i]))
	{
		if (!is_valid_line(error, map, i, &cnt))
			return (0);
		i++;
	}
	if ((i != 0 && !is_valid_border_line(map[i - 1], error, map[i - 1]))
		|| !check_last_spaces(map, i, error))
		return (0);
	return (check_count(cnt, error));
}
