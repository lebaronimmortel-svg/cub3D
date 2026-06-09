/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:10:02 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/09 11:10:05 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	is_valid_square(char c)
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

int	check_adjacent_lines(char **map, int i, int *error)
{
	int	j;
	int	ret;

	ret = 1;
	j = 0;
	if (i > 0)
	{
		while (map[i][j] && map[i - 1][j] && ret)
		{
			if ((map[i][j] == '0' && map[i - 1][j] == ' ')
				|| (map[i - 1][j] == '0' && map[i][j] == ' '))
			{
				*error = 5;
				ret = 0;
			}
			j++;
		}
	}
	return (ret);
}

int	validate_line(char **map, int i, int *cnt, int *error)
{
	int	ret;

	ret = 1;
	if (!is_valid_middle_line(map[i], cnt, error))
		ret = 0;
	if (ret && !check_adjacent_lines(map, i, error))
		ret = 0;
	return (ret);
}
