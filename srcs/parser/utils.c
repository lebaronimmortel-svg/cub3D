/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:47:59 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:18:28 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

int	add_tail(char **str0, char **str1, char **str2)
{
	*str1 = *str2;
	*str2 = ft_strjoin(*str2, *str0);
	free(*str0);
	free(*str1);
	if (!str2)
		return (0);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	my_memlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const	*str1, char const	*str2)
{
	size_t				i;
	size_t				j;
	size_t				cnt;
	char				*tab;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	cnt = ft_strlen(str1) + ft_strlen(str2);
	tab = (char *) malloc ((cnt + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (str1[i] != '\0')
	{
		tab[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		tab[i + j] = str2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
