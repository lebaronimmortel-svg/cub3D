/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:45:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:26 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	has_hole(char *str)
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

static int	check_info_line(int *i, char *str, int *cpt)
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

int	is_ok_format(char *str)
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
		status = check_info_line(&i, str, &cpt);
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

int	assign_color(int flag, t_map *tm, int *token, char *tmp)
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
