/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:45:03 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:32 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

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
	if (!path)
	{
		free(result);
		return (0);
	}
	set_texture(tm, path, flag);
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
		if (!tmp)
			status = 0;
		else
			status = assign_info(tm, i, token, tmp);
		free(tmp);
		if (status == 0)
			break ;
	}
	return (check_number(token));
}
