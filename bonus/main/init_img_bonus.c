/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:07:43 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:29:42 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_bonus/header_bonus.h"

static void	init_shot_img(t_game *g, int *w, int *h)
{
	g->player.shot_anim[0] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_00.png", w, h);
	g->player.shot_anim[1] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_01.png", w, h);
	g->player.shot_anim[2] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_02.png", w, h);
	g->player.shot_anim[3] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_03.png", w, h);
	g->player.shot_anim[4] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_04.png", w, h);
	g->player.shot_anim[5] = mlx_new_image_from_file(g->mlx,
			"player_img/shot_anim/shot_anim_05.png", w, h);
}

static void	init_walk_img(t_game *g, int *w, int *h)
{
	g->player.idle = mlx_new_image_from_file(g->mlx,
			"player_img/img.png", w, h);
	g->player.walk_anim[0] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_00.png", w, h);
	g->player.walk_anim[1] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_00,5.png", w, h);
	g->player.walk_anim[2] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_01.png", w, h);
	g->player.walk_anim[3] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_01,5.png", w, h);
	g->player.walk_anim[4] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_02.png", w, h);
	g->player.walk_anim[5] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_02,5.png", w, h);
	g->player.walk_anim[6] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_03.png", w, h);
	g->player.walk_anim[7] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_03,5.png", w, h);
	g->player.walk_anim[8] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_04.png", w, h);
	g->player.walk_anim[9] = mlx_new_image_from_file(g->mlx,
			"player_img/walk_anim/walk_anim_04,5.png", w, h);
}

static void	init_tex_img(t_game *g, int *w, int *h)
{
	g->map.tex[0] = mlx_new_image_from_file
		(g->mlx, g->map.no, w, h);
	g->map.tex[1] = mlx_new_image_from_file
		(g->mlx, g->map.so, w, h);
	g->map.tex[2] = mlx_new_image_from_file
		(g->mlx, g->map.we, w, h);
	g->map.tex[3] = mlx_new_image_from_file
		(g->mlx, g->map.ea, w, h);
	g->map.tex[4] = mlx_new_image_from_file
		(g->mlx, "map/backroom/png/lock_door.png", w, h);
	g->map.tex[5] = mlx_new_image_from_file
		(g->mlx, "map/backroom/png/door.png", w, h);
}

int	init_img(t_game *g)
{
	int	w;
	int	h;

	init_walk_img(g, &w, &h);
	init_shot_img(g, &w, &h);
	init_tex_img(g, &w, &h);
	g->map.tex_w = w;
	g->map.tex_h = h;
	if (!g->player.idle || !g->map.tex[0] || !g->map.tex[1]
		|| !g->map.tex[2] || !g->map.tex[3] || !g->map.tex[4]
		|| !g->map.tex[5] || !g->player.walk_anim[0]
		|| !g->player.walk_anim[1] || !g->player.walk_anim[2]
		|| !g->player.walk_anim[3] || !g->player.walk_anim[4]
		|| !g->player.walk_anim[5] || !g->player.walk_anim[6]
		|| !g->player.walk_anim[7] || !g->player.walk_anim[8]
		|| !g->player.walk_anim[9] || !g->player.shot_anim[0]
		|| !g->player.shot_anim[1] || !g->player.shot_anim[2]
		|| !g->player.shot_anim[3] || !g->player.shot_anim[4]
		|| !g->player.shot_anim[5])
		return (0);
	return (1);
}

void	update_ray(int flag, t_ray *r)
{
	if (!flag)
	{
		r->sdist_x += r->ddist_x;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->sdist_y += r->ddist_y;
		r->map_y += r->step_y;
		r->side = 1;
	}
}
