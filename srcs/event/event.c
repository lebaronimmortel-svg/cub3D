/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:38:16 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/22 10:38:18 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/header.h"

void	press_escp(int key, void *param)
{
	if (key == 41)
		mlx_loop_end((mlx_context)param);
}

void	press_cross(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}
