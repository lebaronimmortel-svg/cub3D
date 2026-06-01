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

static int	has_hole(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] == ' ')
		i++;
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

static char	*skip_spaces(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

static int	is_ok_format(char *str)
{
	int	i;
	int	value;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i] == ' ')
		i++;
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
			if (is_space(&str[i]))
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

int	check_infos(char **map, int *i, t_map *tm)
{
	char	*result;
	char	*tmp;	
	int		token[6];
	int		j;

	token[0] = 0;
	token[1] = 0;
	token[2] = 0;
	token[3] = 0;
	token[4] = 0;
	token[5] = 0;
	while (map[*i] && !(ft_isdigit(skip_spaces(map[*i])[0])))
	{
		if (is_space(map[*i]))
		{
			(*i)++;
			continue ;
		}
		tmp = ft_strtrim(map[*i], " ");
		if (!ft_strncmp(tmp, "C ", 2) && is_ok_format(&tmp[2]))
		{
			result = ft_strtrim(&tmp[1], " ");
			if (result[ft_strlen(result) - 1] == 9)
				break ;
			tm->ceiling = parse_rgb(result);
			token[0]++;
			(*i)++;
			free(result);
		}
		else if (!ft_strncmp(tmp, "F ", 2) && is_ok_format(&tmp[2]))
		{
			result = ft_strtrim(&tmp[1], " ");
			if (result[ft_strlen(result) - 1] == 9)
				break ;
			tm->floor = parse_rgb(result);
			token[1]++;
			(*i)++;
			free(result);
		}
		else if (!ft_strncmp(tmp, "NO ", 3) && !has_hole(&tmp[4]))
		{
			result = ft_strtrim(&tmp[2], " ");
			if (result[ft_strlen(result) - 1] == 9)
				break ;
			tm->no = ft_strjoin("", skip_spaces(result));
			token[2]++;
			(*i)++;
			free(result);
		}
		else if (!ft_strncmp(tmp, "SO ", 3) && !has_hole(&tmp[4]))
		{
			result = ft_strtrim(&tmp[2], " ");
			if (result[ft_strlen(result) - 1] == 9)
				break ;
			tm->so = ft_strjoin("", skip_spaces(result));
			token[3]++;
			(*i)++;
			free(result);
		}
		else if (!ft_strncmp(tmp, "WE ", 3) && !has_hole(&tmp[4]))
		{
			result = ft_strtrim(&tmp[2], " ");
			if (result[ft_strlen(result) - 1] == 9)
				break ;
			tm->we = ft_strjoin("", skip_spaces(result));
			token[4]++;
			(*i)++;
			free(result);
		}
		else if (!ft_strncmp(tmp, "EA ", 3) && !has_hole(&tmp[4]))
		{
			result = ft_strtrim(&tmp[2], " ");
			if (result[ft_strlen(result) - 1] == 9)
				break ;
			tm->ea = ft_strjoin("", skip_spaces(result));
			token[5]++;
			(*i)++;
			free(result);
		}
		else
		{
			free(tmp);
			break ;
		}
		free(tmp);
	}
	j = 0;
	while (j < 6)
	{
		if (token[j] != 1)
			return (0);
		j++;
	}
	return (1);
}
