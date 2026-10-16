/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 08:06:23 by lukrodri          #+#    #+#             */
/*   Updated: 2026/06/05 07:30:24 by lukrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -------------------------- */
/* ---------- parser -------- */
/* -------------------------- */

/* ---------- file ---------- */
int			is_valid_name(char *filename);
int			main_parser(int argc, char **argv, t_game *g);
int			content_error_check(int fd, char *str2, int *error);
void		update_status(char *str, int i, int *error);
int			add_tail(char **str0, char **str1, char **str2);

/* ---------- map ---------- */
char		**create_map(char *filename, int *error, t_map *tm);
int			check_square(char *str, int *i, int *error, int *ind_P);
int			item_count(char **map, int *error, int *start, t_map *tm);
int			is_suround_diff(char **map);
int			is_valid_middle_line(char *str, int *ind_P, int *error);
int			is_valid_border_line(char *str, int *error, char *pre_str);
int			check_enclosure(int *error, char **map, int i);
int			check_last_spaces(char **map, int i, int *error);
int			check_begin(char *str, int *i, int *error);
int			check_line_end(char *str, int *i, int *error);
void		free_map(char **map);

/* ---------- infos ---------- */
int			has_hole(char *str);
int			check_infos(char **map, int *i, t_map *tm);
int			is_ok_format(char *str);
int			assign_color(int flag, t_map *tm, int *token, char *tmp);
void		set_texture(t_map *tm, char *path, int flag);

/* ---------- utils ---------- */
char		**my_ft_split(char const *s, char c);
int			my_memlen(char **map);
int			my_space_strlen(char *str);
int			is_space(char *str);
char		*skip_spaces(char *str);

/* -------------------------- */
/* ---------- game ---------- */
/* -------------------------- */

/* ---------- init ---------- */
void		init_player(t_game *g);
int			init_windows_mlx(t_game *g);
void		init_events(t_game *g);
void		init_game(void *ptr);
int			init_img(t_game *g);

/* ---------- init_utils ---------- */
void		init_ray(t_game *g, t_ray *r, int x);
void		init_dda(t_game *g, t_ray *r);
int			dda_loop(t_game *g, t_ray *r, int x);
mlx_color	get_tex_color(t_game *g, t_ray *r, int tex_y, int hit);
void		draw_col(t_game *g, t_ray *r, int x, int hit);

/* ---------- events ---------- */
void		press_escp(int key, void *param);
void		press_cross(int event, void *param);
void		key_down(int key, void *param);
void		set_player_dir_vec(t_game *g, char c);
void		set_player_plane(t_game *g, char c);
void		key_up(int key, void *param);
void		mouse_up(int key, void *param);
void		mouse_down(int key, void *param);
t_color		parse_rgb(char *str);
void		draw_col(t_game *g, t_ray *r, int x, int hit);

/* ---------- raycasting ---------- */
int			is_wall(t_game *g, int wx, int wy);
mlx_color	rgb(int r, int g, int b);
void		draw_floor_ceiling(t_game *g);
int			pick_tex(int side, int step_x, int step_y);
void		cast_ray(t_game *g, int x);
void		draw_scene(t_game *g);
void		update_ray(int flag, t_ray *r);

/* ---------- free ---------- */
void		free_game(t_game *g);
void		end_game(t_game *g, int flag);
void		close_img(int one, int two, int three, int four);
void		free_map_info(t_game *g);

/* ---------- move_utils ---------- */
void		forward(t_game *g, double ms);
void		backward(t_game *g, double ms);
void		left(t_game *g, double rs);
void		right(t_game *g, double rs);
void		update_move(t_game *g, double ms, double rs);
void		straf_left(t_game *g, double ms);
void		straf_right(t_game *g, double ms);

/* ---------- animation ---------- */
void		display_hands(t_game *g);
int			is_door(t_game *g, int i, int j);

/* ---------- minimap ---------- */
void		draw_minimap(t_game *g);
