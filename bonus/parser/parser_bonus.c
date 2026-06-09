/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:48:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:29:02 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static int	is_valid_square(char c)
{
	char	array[7];
	int		i;

	array[0] = 'N';
	array[1] = 'W';
	array[2] = 'S';
	array[3] = '0';
	array[4] = '1';
	array[5] = 'E';
	array[6] = ' ';
	i = 0;
	while (i < 7)
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_line_end(char *str, int *i, int *error)
{
	if (str[*i] == '\0')
	{
		while (*i - 1 >= 0 && str[*i - 1] != '1')
		{
			if (str[*i - 1] != ' ')
			{
				*error = 5;
				return (0);
			}
			(*i)--;
		}
	}
	return (1);
}

int	check_square(char *str, int *i, int *error, int *ind_P)
{
	if (!is_valid_square(str[*i]))
	{
		*error = 4;
		return (0);
	}
	if (str[*i] == 'W' || str[*i] == 'N'
		|| str[*i] == 'S' || str[*i] == 'E')
		(*ind_P)++;
	(*i)++;
	return (1);
}

static int	check_begin(char *str, int *i, int *error)
{
	if (!str)
		return (0);
	*i = 0;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != '1' && !is_space(str))
	{
		*error = 4;
		return (0);
	}
	*i = 1;
	while (str[*i] == ' ')
		(*i)++;
	return (1);
}

static void	update_status(char *str, int i, int *error)
{
	if (str[i] == '0')
		*error = 5;
	else
		*error = 4;
}

static int	is_valid_middle_line(char *str, int *ind_P, int *error)
{
	int	i;

	if (!check_begin(str, &i, error))
		return (0);
	while (str[i])
	{
		if (!check_square(str, &i, error, ind_P))
			return (0);
		if (str[i] == ' ')
		{
			if (str[i - 1] != '1')
				*error = 5;
			if (str[i - 1] != '1')
				return (0);
			while (str[i] && (str[i] == ' '))
				i++;
			if (str[i] == '\0')
				break ;
			if (str[i] != '1')
				update_status(str, i, error);
			if (str[i] != '1')
				return (0);
		}
	}
	return (check_line_end(str, &i, error));
}

int	content_error_check(int fd, char *str2, int *error)
{
	if (!str2 || *error != 7)
	{
		if (str2)
			free(str2);
		if (fd >= 0)
			close(fd);
		return (0);
	}
	return (1);
}

int	is_space(char *str)
{
	int	i;

	if (!(*str))
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_enclosure(int *error, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] && map[i - 1][j])
	{
		if (map[i][j] == '0' && (map[i - 1][j] == ' '))
		{
			*error = 5;
			return (0);
		}
		if (map[i - 1][j] == '0' && (map[i][j] == ' '))
		{
			*error = 5;
			return (0);
		}
		j++;
	}
	return (1);
}

static int	check_last_spaces(char **map, int i, int *error)
{
	while (map[i])
	{
		if (!is_space(map[i]))
		{
			*error = 4;
			return (0);
		}
		i++;
	}
	return (1);
}

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
	if (i == 0)
	{
		if (!is_valid_border_line(map[i], error, map[i + 1]))
			return (0);
	}
	else
	{
		if (!is_valid_middle_line(map[i], cnt, error))
			return (0);
	}
	if (i != 0)
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
	flag = 0;
	while (map[i] && !is_space(map[i]))
	{
		if (!is_valid_line(error, map, i, &cnt))
			return (0);
		i++;
	}
	if (i != 0 && !is_valid_border_line(map[i - 1], error, map[i - 1]))
		return (0);
	if (!check_last_spaces(map, i, error))
		return (0);
	return (check_count(cnt, error));
}
