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

static int	file_error_check(char *filename, int *error)
{
	int	fd;

	if (!is_valid_name(filename) || ft_strlen(filename) < 5)
		*error = 3;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		*error = 8;
	return (fd);
}

static char	**read_from_file(char *filename, int *error)
{
	char	*str0;
	char	*str1;
	char	*str2;
	char	**map;
	int		fd;

	fd = file_error_check(filename, error);
	str2 = malloc(1);
	if (!content_error_check(fd, str2, error))
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
	map = my_ft_split(str2, '\n');
	free(str2);
	close(fd);
	return (map);
}

static char	**trim_map_header(char **map, int start)
{
	int		i;
	int		new_len;
	char	**new_map;

	new_len = 0;
	while (map[start + new_len])
		new_len++;
	new_map = malloc(sizeof(char *) * (new_len + 1));
	if (!new_map)
		free_map(map);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < start)
		free(map[i++]);
	i = 0;
	while (i < new_len)
	{
		new_map[i] = map[start + i];
		i++;
	}
	new_map[i] = NULL;
	free(map);
	return (new_map);
}

char	**create_map(char *filename, int *error, t_map *tm)
{
	char	**map;
	int		start;

	start = 0;
	map = read_from_file(filename, error);
	if (!map)
		return (NULL);
	if (!item_count(map, error, &start, tm))
	{
		free_map(map);
		return (NULL);
	}
	map = trim_map_header(map, start);
	if (!map)
	{
		*error = 9;
		return (NULL);
	}
	if (*error == 7)
		return (map);
	free_map(map);
	return (NULL);
}
