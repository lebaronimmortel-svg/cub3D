/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:45:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:26 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	error_check(char *filename, int *error)
{
	int	fd;

	if (!is_valid_name(filename) || ft_strlen(filename) < 5)
		*error = 2;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*error = 3;
	return (fd);
}

static char	**read_from_file(char *filename, int *error)
{
	char	*str0;
	char	*str1;
	char	*str2;
	char	**map;
	int		fd;

	fd = error_check(filename, error);
	str2 = malloc(1);
	if (!error_check2(fd, str2, error))
		return (NULL);
	*(str2) = '\0';
	str0 = get_next_line(fd);
	while (str0)
	{
		if (!add_tail(&str0, &str1, &str2))
		{
			close(fd);
			return (NULL);
		}
		str0 = get_next_line(fd);
	}
	map = ft_split(str2, '\n');
	free(str2);
	close(fd);
	return (map);
}

char	**create_map(char *filename, int *error)
{
	char	**map;

	map = read_from_file(filename, error);
	if (!map)
		return (NULL);
	if (!item_count(map, error))
	{
		if (*error == 0 || *error == 6 || *error == 7)
			*error = 4;
		free_map(map);
		return (NULL);
	}
	if (*error == 0)
		return (map);
	free_map(map);
	return (NULL);
}
