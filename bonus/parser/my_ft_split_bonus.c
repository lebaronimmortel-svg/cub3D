/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:38:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/06/05 07:28:53 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static void	free_memory(char **s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free(s);
}

static size_t	count_str(char const	*str, char c)
{
	size_t	i;
	size_t	cpt;

	cpt = 0;
	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] != c)
		cpt += 1;
	while (str[i + 1] != '\0')
	{
		if (str[i] == c)
			cpt += 1;
		i++;
	}
	return (cpt + 1);
}

static void	fill_str(char **tab, char const *str, size_t size, size_t *arr)
{
	size_t		j;

	tab[arr[0]] = (char *) malloc ((size + 1) * sizeof(char));
	if (!tab[arr[0]])
		return ;
	j = 0;
	while (j < size)
	{
		tab[arr[0]][j] = str[arr[1]];
		j++;
		arr[1]++;
	}
	tab[arr[0]][j] = '\0';
}

static void	loop(char **tab, char const	*str, char c)
{
	size_t		size;	
	size_t		arr[2];

	arr[0] = 0;
	arr[1] = 0;
	while (arr[0] < count_str(str, c))
	{
		size = 0;
		while (str[arr[1] + size] && str[arr[1] + size] != c)
			size++;
		fill_str(tab, str, size, arr);
		if (!tab[arr[0]])
			return ;
		arr[0]++;
		arr[1]++;
	}
}

char	**my_ft_split(char const	*s, char c)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **) malloc ((count_str(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	loop(tab, s, c);
	i = 0;
	while (i < count_str(s, c))
	{
		if (!tab[i])
		{
			free_memory(tab);
			return (NULL);
		}
		i++;
	}
	tab[count_str(s, c)] = NULL;
	return (tab);
}
