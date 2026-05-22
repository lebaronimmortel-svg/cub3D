/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:06:23 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/20 08:06:25 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_player(t_game *g);
void	init_windows_mlx(t_game *g);
void	init_events(t_game *g);
void	init_game(void *ptr);

void	press_escp(int key, void *param);
void	press_cross(int event, void *param);

void	ray_pos_dir(t_game *g);
void	grid(t_game *g);
