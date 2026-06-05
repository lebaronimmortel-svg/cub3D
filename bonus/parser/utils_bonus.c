/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:47:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:29:26 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	my_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	add_tail(char **str0, char **str1, char **str2)
{
	*str1 = *str2;
	*str2 = ft_strjoin(*str2, *str0);
	free(*str0);
	free(*str1);
	if (!str2)
		return (0);
	return (1);
}

int	my_memlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	is_wall(t_game *g, int wx, int wy)
{
	if (wy < 0 || wx < 0 || !g->map.grid_map[wy])
		return (1);
	if (!g->map.grid_map[wy][wx])
		return (1);
	return (g->map.grid_map[wy][wx] == '1');
}
