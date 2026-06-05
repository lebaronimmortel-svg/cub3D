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
char	**my_ft_split(char const *s, char c);
int		my_space_strlen(char *str);
void	free_map(char **map);
int		is_space(char *str);
int		my_memlen(char **map);
int		is_suround_diff(char **map);
int		is_valid_name(char *filename);
int		is_valid_border_line(char *str, int *error, char *pre_str);
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
void	set_player_dir_vec(t_game *g, char c);
void	set_player_plane(t_game *g, char c);
void	key_up(int key, void *param);
void	mouse_up(int key, void *param);
void	mouse_down(int key, void *param);
void    timer(t_game *g);

/* ---------- raycasting ---------- */
int	        is_wall(t_game *g, int wx, int wy);
mlx_color	rgb(int r, int g, int b);
void	    draw_floor_ceiling(t_game *g);
int	        pick_tex(int side, int step_x, int step_y);
void	    cast_ray(t_game *g, int x);
void	    draw_scene(t_game *g);

/* ---------- free ---------- */
void	free_game(t_game *g);
void	end_game(t_game *g);
void	close_img(int one, int two, int three, int four);

/* ---------- move_utils ---------- */
void	forward(t_game *g, double ms);
void	backward(t_game *g, double ms);
void	left(t_game *g, double rs);
void	right(t_game *g, double rs);
void	update_move(t_game *g, double ms, double rs);

/* ---------- animation ---------- */
void    display_hands(t_game *g);
int	    is_door(t_game *g, int i, int j);

/* ---------- init_utils ---------- */
void		init_ray(t_game *g, t_ray *r, int x);
void		init_dda(t_game *g, t_ray *r);
int		    dda_loop(t_game *g, t_ray *r);
mlx_color	get_tex_color(t_game *g, t_ray *r, int tex_y, int hit);
void		draw_col(t_game *g, t_ray *r, int x, int hit);
