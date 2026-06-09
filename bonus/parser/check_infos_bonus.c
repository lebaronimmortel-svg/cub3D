/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:45:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:32 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

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

static int	fonction_y(int *i, char *str, int *cpt)
{
	int	value;

	value = ft_atoi(&str[*i]);
	if (value < 0 || value > 255)
		return (0);
	else
		*cpt += 1;
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (!str[*i])
		return (-1);
	else if (str[*i] == ',' && ft_isdigit(str[*i + 1]))
		(*i)++;
	else if (!ft_isdigit(str[*i]))
	{
		if (is_space(&str[*i]))
			return (-1);
		else
			return (0);
	}
	return (1);
}

static int	is_ok_format(char *str)
{
	int	i;
	int	cpt;
	int	status;

	i = 0;
	cpt = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		status = fonction_y(&i, str, &cpt);
		if (!status)
			return (0);
		else if (status == -1)
			break ;
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

static int	assign_color(int flag, t_map *tm, int *token, char *tmp)
{
	char	*result;

	result = ft_strtrim(&tmp[1], " ");
	if (!result)
		return (0);
	if (result[ft_strlen(result) - 1] == 9)
		return (free(result), 0);
	if (flag == 0)
		tm->ceiling = parse_rgb(result);
	else if (flag == 1)
		tm->floor = parse_rgb(result);
	token[flag]++;
	free(result);
	return (1);
}

static int	assign_tex(int flag, t_map *tm, int *token, char *tmp)
{
	char	*result;
	char	*path;

	result = ft_strtrim(&tmp[2], " ");
	if (!result)
		return (0);
	if (result[ft_strlen(result) - 1] == 9)
		return (free(result), 0);
	path = ft_strjoin("", skip_spaces(result));
	if (flag == 2)
		tm->no = path;
	else if (flag == 3)
		tm->so = path;
	else if (flag == 4)
		tm->we = path;
	else if (flag == 5)
		tm->ea = path;
	token[flag]++;
	free(result);
	return (1);
}

static int	check_number(int *token)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (token[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

static void	init_array(int *token)
{
	token[0] = 0;
	token[1] = 0;
	token[2] = 0;
	token[3] = 0;
	token[4] = 0;
	token[5] = 0;
}

static int	assign_info(t_map *tm, int *i, int *token, char *tmp)
{
	int	status;

	if (!ft_strncmp(tmp, "C ", 2) && is_ok_format(&tmp[2]))
		status = assign_color(0, tm, token, tmp);
	else if (!ft_strncmp(tmp, "F ", 2) && is_ok_format(&tmp[2]))
		status = assign_color(1, tm, token, tmp);
	else if (!ft_strncmp(tmp, "NO ", 3) && !has_hole(&tmp[4]))
		status = assign_tex(2, tm, token, tmp);
	else if (!ft_strncmp(tmp, "SO ", 3) && !has_hole(&tmp[4]))
		status = assign_tex(3, tm, token, tmp);
	else if (!ft_strncmp(tmp, "WE ", 3) && !has_hole(&tmp[4]))
		status = assign_tex(4, tm, token, tmp);
	else if (!ft_strncmp(tmp, "EA ", 3) && !has_hole(&tmp[4]))
		status = assign_tex(5, tm, token, tmp);
	else
	{
		status = 0;
		(*i)--;
	}
	(*i)++;
	return (status);
}

int	check_infos(char **map, int *i, t_map *tm)
{
	char	*tmp;
	int		token[6];
	int		status;

	init_array(token);
	while (map[*i] && !(ft_isdigit(skip_spaces(map[*i])[0])))
	{
		if (is_space(map[*i]))
		{
			(*i)++;
			continue ;
		}
		tmp = ft_strtrim(map[*i], " ");
		status = assign_info(tm, i, token, tmp);
		free(tmp);
		if (status == 0)
			break ;
	}
	return (check_number(token));
}
