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


void	free_map(char **map);
int		my_memlen(char **map);
int     is_suround_diff(char **map);
int		is_valid_name(char *filename);
int		is_valid_border_line(char *str);
int     check_infos(char **map, int *i);
int		item_count(char **map, int *error);
char	**create_map(char *filename, int *error);
void	spawn_exit_coord(char **map, int *coord);
void	flood_fill(char **map, int p_y, int p_x);
int		error_check2(int fd, char *str2, int *error);
int		add_tail(char **str0, char **str1, char **str2);
int		main_parser(int argc, char **argv);

void	init_player(t_game *g);
void	init_windows_mlx(t_game *g);
void	init_events(t_game *g);
void	init_game(void *ptr);

void	press_escp(int key, void *param);
void	press_cross(int event, void *param);

void	ray_pos_dir(t_game *g);
void	grid(t_game *g);
