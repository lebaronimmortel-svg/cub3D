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

static int	is_valid_square(char c)
{
	char	array[6];
	int		i;

	array[0] = 'N';
	array[1] = 'W';
	array[2] = 'S';
	array[3] = '0';
	array[4] = '1';
	array[5] = 'E';
	i = 0;
	while (i < 6)
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_middle_line(char *str, int *ind_P)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '1')
		return (0);
	i = 1;
	while (str[i])
	{
		if (!is_valid_square(str[i]))
			return (0);
		if (str[i] == 'W' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'E')
			(*ind_P)++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] == '1')
		return (1);
	return (0);
}

static int	is_valid_line(char **map, int i, int *p_cnt)
{
	if (i == 0 || i == my_memlen(map) - 1)
	{
		if (!is_valid_border_line(map[i]))
			return (0);
	}
	else
	{
		if (!is_valid_middle_line(map[i], p_cnt))
			return (0);
	}
	return (1);
}

int	error_check2(int fd, char *str2, int *error)
{
	if (!str2 || *error != 0)
	{
		if (str2)
			free(str2);
		if (fd >= 0)
			close(fd);
		return (0);
	}
	return (1);
}

int	item_count(char **map, int *error, int *start, t_map *tm)
{
	int	i;
	int	cnt;

	if (!map || !(*map))
		return (0);
	i = 0;
	cnt = 0;
	if (!check_infos(map, &i, tm))
		return (0);
	*start = i;
	if (!is_suround_diff(&map[i]))
		return (0);
	while (map[i])
	{
		if (!is_valid_line(map, i, &cnt))
		{
			*error = 4;
			return (0);
		}
		i++;
	}
	if (cnt != 1)
		return (0);
	return (1);
}
