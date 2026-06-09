/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:37:26 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/09 10:37:27 by lukrodri         ###   ########.fr       */
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

char	*skip_spaces(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ')
		i++;
	return (&str[i]);
}

int	is_ok_format_sec(char *str, int *i, int *cpt)
{
	int	value;

	value = ft_atoi(&str[*i]);
	if (value < 0 || value > 255)
		return (0);
	else
		*cpt += 1;
	return (1);
}

int	is_ok_format(char *str, int i, int cpt)
{
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!is_ok_format_sec(str, &i, &cpt))
			return (0);
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

t_color	parse_rgb(char *str)
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
