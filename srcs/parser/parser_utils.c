/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:52:09 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:53 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s2[i] != s1[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

static int	check_line(char *str, int i, int *error, char *pre_str)
{
	if (i > 0 && (str[i - 1] == ' '))
	{
		if (my_space_strlen(str) > my_space_strlen(pre_str)
			|| pre_str[i] == ' ')
		{
			*error = 4;
			return (0);
		}
	}
	return (1);
}

int	is_valid_border_line(char *str, int *error, char *pre_str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != ' ')
		{
			if (str[i] == '0')
				*error = 5;
			else
				*error = 4;
			return (0);
		}
		if (str[i] == '1' && is_space(&str[i + 1]))
			if (!check_line(str, i, error, pre_str))
				return (0);
		i++;
	}
	return (1);
}

int	is_valid_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".cub", 4))
		return (0);
	return (1);
}

int	my_space_strlen(char *str)
{
	int	len;

	if (!str || !(*str))
		return (0);
	len = 0;
	while (str[len])
	{
		if ((str[len] == ' ') && is_space(&str[len]))
			return (len - 1);
		len++;
	}
	return (len);
}
