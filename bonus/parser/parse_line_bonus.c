/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:38:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:53 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static int	is_valid_square(char c)
{
	char	array[7];
	int		i;

	array[0] = 'N';
	array[1] = 'W';
	array[2] = 'S';
	array[3] = '0';
	array[4] = '1';
	array[5] = 'E';
	array[6] = ' ';
	i = 0;
	while (i < 7)
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_line_end(char *str, int *i, int *error)
{
	if (str[*i] == '\0')
	{
		while (*i - 1 >= 0 && str[*i - 1] != '1')
		{
			if (str[*i - 1] != ' ')
			{
				*error = 5;
				return (0);
			}
			(*i)--;
		}
	}
	return (1);
}

int	check_square(char *str, int *i, int *error, int *ind_P)
{
	if (!is_valid_square(str[*i]))
	{
		*error = 4;
		return (0);
	}
	if (str[*i] == 'W' || str[*i] == 'N'
		|| str[*i] == 'S' || str[*i] == 'E')
		(*ind_P)++;
	(*i)++;
	return (1);
}

int	check_begin(char *str, int *i, int *error)
{
	if (!str)
		return (0);
	*i = 0;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != '1' && !is_space(str))
	{
		*error = 4;
		return (0);
	}
	*i = 1;
	while (str[*i] == ' ')
		(*i)++;
	return (1);
}

void	update_status(char *str, int i, int *error)
{
	if (str[i] == '0')
		*error = 5;
	else
		*error = 4;
}
