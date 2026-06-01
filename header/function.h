/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:06:23 by lukrodri          #+#    #+#             */
/*   Updated: 2026/05/27 09:00:00 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ---------- parser / utils ---------- */
int		my_space_strlen(char *str);
void	free_map(char **map);
int		is_space(char *str);
int		my_memlen(char **map);
int		is_suround_diff(char **map);
int		is_valid_name(char *filename);
int		is_valid_border_line(char *str, int *error);
int		check_infos(char **map, int *i, t_map *tm);
int		item_count(char **map, int *error, int *start, t_map *tm);
char	**create_map(char *filename, int *error, t_map *tm);
void	spawn_exit_coord(char **map, int *coord);
void	flood_fill(char **map, int p_y, int p_x);
int		content_error_check(int fd, char *str2, int *error);
int		add_tail(char **str0, char **str1, char **str2);
int		main_parser(int argc, char **argv, t_game *g);

/* ---------- init ---------- */
void	init_player(t_game *g);
void	init_windows_mlx(t_game *g);
void	init_events(t_game *g);
void	init_game(void *ptr);
int		init_img(t_game *g);

/* ---------- events ---------- */
void	press_escp(int key, void *param);
void	press_cross(int event, void *param);
void	key_down(int key, void *param);
void	key_up(int key, void *param);

/* ---------- raycasting ---------- */
void	draw_floor_ceiling(t_game *g);
void	cast_ray(t_game *g, int x);
void	draw_scene(t_game *g);
void	update_move(t_game *g, double ft);

/* ---------- free ---------- */
void	free_game(t_game *g);
void	end_game(t_game *g);
void	close_img(int one, int two, int three, int four);

/* ---------- utils ---------- */
void	init_player_at(t_game *g, int x, int y, char c);