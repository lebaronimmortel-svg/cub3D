/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suround_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:48:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:42 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	is_suround_up(char **map, int i)
{
	int	j;

	j = 0;
	if (!map[i + 1])
		return (1);
	while (j < my_space_strlen(map[i + 1]))
		j++;
	if (j > my_space_strlen(map[i]))
		return (1);
	while (j <= my_space_strlen(map[i]))
	{
		if (map[i][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

static int	is_suround_down(char **map, int i)
{
	int	j;

	j = 0;
	while (j < my_space_strlen(map[i - 1]))
		j++;
	if (j > my_space_strlen(map[i]))
		return (1);
	while (j <= my_space_strlen(map[i]))
	{
		if (map[i][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

int	is_suround_diff(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (my_space_strlen(map[i]) > my_space_strlen(map[i - 1]))
		{
			if (!is_suround_down(map, i))
				return (0);
		}
		else if (my_space_strlen(map[i]) < my_space_strlen(map[i - 1]))
		{
			if (!is_suround_up(map, i - 1))
				return (0);
		}
		i++;
	}
	return (1);
}
