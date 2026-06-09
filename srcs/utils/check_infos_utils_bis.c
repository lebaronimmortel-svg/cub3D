/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos_utils_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:39:19 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/09 10:39:21 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

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
