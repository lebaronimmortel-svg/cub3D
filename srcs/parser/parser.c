/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:48:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:42 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	is_valid_middle_line(char *str, int *ind_P, int *error)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '1' && !is_space(str))
	{
		*error = 4;
		return (0);
	}
	i = 1;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!is_valid_square(str[i]))
		{
			*error = 4;
			return (0);
		}
		if (str[i] == 'W' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'E')
			(*ind_P)++;
		i++;
		if (str[i] == ' ')
		{
			if (str[i - 1] != '1')
			{
				*error = 5;
				return (0);
			}
			while (str[i] && (str[i] == ' '))
				i++;
			if (str[i] == '\0')
				break ;
			if (str[i] != '1')
			{
				if (str[i] == '0')
				{
					*error = 5;
				}
				else
					*error = 4;
				return (0);
			}
		}
	}
	if (str[i] == '\0')
	{
		while (i - 1 >= 0 && str[i - 1] != '1')
		{
			if (str[i - 1] != ' ')
			{
				*error = 5;
				return (0);
			}
			i--;
		}
	}
	return (1);
}

static int	process_map(char **map, int *idx, int *cnt, int *error)
{
	int	i;
	int	first;
	int	ret;

	i = *idx;
	first = 0;
	ret = 1;
	while (map[i] && !is_space(map[i]) && ret)
	{
		if (!first)
		{
			first = 1;
			if (!is_valid_border_line(map[i], error, map[i + 1]))
				ret = 0;
		}
		else if (!validate_line(map, i, cnt, error))
			ret = 0;
		i++;
	}
	*idx = i;
	return (ret);
}

static int	check_end(char **map, int i, int *error)
{
	int	ret;

	ret = 1;
	while (map[i] && ret)
	{
		if (!is_space(map[i]))
		{
			*error = 4;
			ret = 0;
		}
		i++;
	}
	return (ret);
}

static int	init_check(char **map, int *error, int *start, t_map *tm)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (!check_infos(map, &i, tm))
	{
		*error = 6;
		ret = 0;
	}
	while (ret && is_space(map[i]))
		i++;
	if (ret)
		*start = i;
	if (ret && !is_suround_diff(&map[i]))
	{
		*error = 5;
		ret = 0;
	}
	return (ret);
}

int	item_count(char **map, int *error, int *start, t_map *tm)
{
	int	i;
	int	cnt;
	int	ret;

	cnt = 0;
	ret = 1;
	if (!map || !*map)
		ret = 0;
	if (ret && !init_check(map, error, start, tm))
		ret = 0;
	if (ret)
		i = *start;
	if (ret && !process_map(map, &i, &cnt, error))
		ret = 0;
	if (ret && i > 0
		&& !is_valid_border_line(map[i - 1], error, map[i - 1]))
		ret = 0;
	if (ret && !check_end(map, i, error))
		ret = 0;
	if (ret && cnt != 1)
	{
		*error = 0;
		ret = 0;
	}
	return (ret);
}
