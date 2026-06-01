/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:48:27 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/17 18:17:42 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../header/header.h"

int my_space_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
    {
        if ((str[len] == ' ' || str[len] == 9) && is_space(&str[len]))
            return (len - 1);
        len++;
    }
    return (len);
}

int is_suround_diff(char **map)
{
    int i;
    int j;

    i = 1;
    while (map[i])
    {
        if (my_space_strlen(map[i]) > my_space_strlen(map[i - 1]))
        {
            j = 0;
            while (map[i - 1][j])
                j++;
            while (map[i][j])
            {
                if (map[i][j] != '1')
                    return (0);
                j++;
            }
        }
        else if (my_space_strlen(map[i]) < my_space_strlen(map[i - 1]))
        {
            j = 0;
            while (map[i][j])
                j++;
            while (map[i - 1][j])
            {
                if (map[i - 1][j] != '1')
                    return (0);
                j++;
            }
        }
        i++;
    }
    return (1);


}
