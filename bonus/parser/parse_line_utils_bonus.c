/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:38:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:53 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

int	is_valid_middle_line(char *str, int *ind_P, int *error)
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

int	check_enclosure(int *error, char **map, int i)
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

int	check_last_spaces(char **map, int i, int *error)
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
