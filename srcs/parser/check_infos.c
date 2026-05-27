/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:45:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:26 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

static int	is_whitespace_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] > 8 && line[i] < 14) || line[i] == 32)
			return (0);
		i++;
	}
	return (1);
}

static int	has_hole(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			flag = 1;
		else
		{
			if (flag == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

static int	is_texture_text(char **map, int *i, t_map *tm)
{
	int	no;
	int	so;
	int	we;
	int	ea;

	no = 0;
	so = 0;
	we = 0;
	ea = 0;
	while (map[*i] && !is_whitespace_line(map[*i]))
	{
		if (!ft_strncmp(map[*i], "NO ./", 5) && !has_hole(&map[*i][4]))
		{
			no++;
			tm->NO = ft_strjoin("", &map[*i][3]);
			(*i)++;
		}
		else if (!ft_strncmp(map[*i], "SO ./", 5) && !has_hole(&map[*i][4]))
		{
			so++;
			tm->SO = ft_strjoin("", &map[*i][3]);
			(*i)++;
		}
		else if (!ft_strncmp(map[*i], "WE ./", 5) && !has_hole(&map[*i][4]))
		{
			we++;
			tm->WE = ft_strjoin("", &map[*i][3]);
			(*i)++;
		}
		else if (!ft_strncmp(map[*i], "EA ./", 5) && !has_hole(&map[*i][4]))
		{
			ea++;
			tm->EA = ft_strjoin("", &map[*i][3]);
			(*i)++;
		}
		else
			break ;
	}
	if (no != 1 || so != 1 || we != 1 || ea != 1)
		return (0);
	return (1);
}

static int	is_ok_format(char *str)
{
	int	i;
	int	value;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		value = ft_atoi(&str[i]);
		if (value < 0 || value > 255)
			return (0);
		else
			cpt += 1;
		while (ft_isdigit(str[i]))
			i++;
		if (!str[i])
			break ;
		else if (str[i] == ',' && ft_isdigit(str[i + 1]))
			i++;
		else if (!ft_isdigit(str[i]))
		{
			if (is_whitespace_line(&str[i]))
				break ;
			else
				return (0);
		}
	}
	if (cpt != 3)
		return (0);
	return (1);
}

static t_color	parse_rgb(char *str)
{
	t_color	c;

	c.r = ft_atoi(str);
	while (*str && *str != ',')
		str++;
	if (*str)
		str++;
	c.g = ft_atoi(str);
	while (*str && *str != ',')
		str++;
	if (*str)
		str++;
	c.b = ft_atoi(str);
	return (c);
}

static int	is_color_text(char **map, int *i, t_map *tm)
{
	int	c;
	int	f;

	c = 0;
	f = 0;
	while (map[*i] && !is_whitespace_line(map[*i]))
	{
		if (!ft_strncmp(map[*i], "C ", 1) && is_ok_format(&map[*i][2]))
		{
			c++;
			tm->ceiling = parse_rgb(&map[*i][2]);
			(*i)++;
		}
		else if (!ft_strncmp(map[*i], "F ", 1) && is_ok_format(&map[*i][2]))
		{
			f++;
			tm->floor = parse_rgb(&map[*i][2]);
			(*i)++;
		}
		else
			break ;
	}
	if (c != 1 || f != 1)
		return (0);
	return (1);
}

int	check_infos(char **map, int *i, t_map *tm)
{
	while (map[*i] && is_whitespace_line(map[*i]))
		(*i)++;
	if (is_color_text(map, i, tm))
	{
		while (map[*i] && is_whitespace_line(map[*i]))
			(*i)++;
		if (is_texture_text(map, i, tm))
		{
			while (map[*i] && is_whitespace_line(map[*i]))
				(*i)++;
			return (1);
		}
		return (0);
	}
	else if (is_texture_text(map, i, tm))
	{
		while (map[*i] && is_whitespace_line(map[*i]))
			(*i)++;
		if (is_color_text(map, i, tm))
		{
			while (map[*i] && is_whitespace_line(map[*i]))
				(*i)++;
			return (1);
		}
		return (0);
	}
	return (0);
}
