NAME        = cub3D
NAME_BNS	= cub3D_bonus

# --- Directories ---
SRC_DIR     = srcs
OBJ_DIR_BNS = objs_bonus
OBJ_DIR     = objs
LIBFT_DIR   = libft
HEADER_DIR  = header
MLX 		= ./MacroLibX/libmlx.so

# --- Files ---
SRC         =	srcs/main/main.c \
				srcs/main/init.c \
				srcs/parser/parser.c \
				srcs/parser/utils.c \
				srcs/parser/parser_utils.c \
				srcs/parser/parse_line.c \
				srcs/parser/parse_line_utils.c \
				srcs/parser/suround_diff.c \
				srcs/parser/main_parser.c \
				srcs/parser/create_map.c \
				srcs/parser/my_ft_split.c \
				srcs/parser/check_infos.c \
				srcs/parser/check_infos_utils.c \
				srcs/raycasting/raycasting.c \
				srcs/utils/utils.c \
				srcs/utils/move_utils.c \
				srcs/utils/init_utils.c \
				srcs/event/event.c \
				srcs/free/free_game.c \
				srcs/utils/straf.c

BNS			= 	bonus/main/main_bonus.c \
			    bonus/main/init_bonus.c \
				bonus/main/init_img_bonus.c \
			    bonus/parser/parser_bonus.c \
				bonus/parser/parse_line_bonus.c \
				bonus/parser/parse_line_utils_bonus.c \
			    bonus/parser/utils_bonus.c \
			    bonus/parser/parser_utils_bonus.c \
			    bonus/parser/suround_diff_bonus.c \
			    bonus/parser/main_parser_bonus.c \
			    bonus/parser/create_map_bonus.c \
			    bonus/parser/my_ft_split_bonus.c \
			    bonus/parser/check_infos_bonus.c \
				bonus/parser/check_infos_utils_bonus.c \
			    bonus/raycasting/raycasting_bonus.c \
				bonus/raycasting/raycasting_utils_bonus.c \
				bonus/event/event_bonus.c \
			    bonus/event/mouse_event_bonus.c \
			    bonus/event/keyboard_event_bonus.c \
				bonus/event/animation_bonus.c \
			    bonus/free/free_game_bonus.c \
				bonus/utils/init_utils_bonus.c \
				bonus/utils/move_utils_bonus.c \
				bonus/utils/utils_bonus.c \
				bonus/minimap/minimap_bonus.c \
				bonus/utils/straf_bonus.c

OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BNS     = $(BNS:%.c=$(OBJ_DIR_BNS)/%.o)
HEADERS 	= header/typedef.h header/function.h header/header.h
HEADER_BNS	= header_bonus/typedef_bonus.h header_bonus/function_bonus.h header_bonus/header_bonus.h
LIBFT       = $(LIBFT_DIR)/libft.a
HEADER_DIR_BNS = header_bonus

CC          = cc
FLAGS       = -Wall -Wextra -Werror -g
RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $^ -lSDL2 -lXext -lX11 -lm -O3 -o $(NAME)
	
bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $^ -lSDL2 -lXext -lX11 -lm -o $@

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@
	
$(OBJ_DIR_BNS)/%.o: %.c $(HEADERS_BNS)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_DIR_BNS) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C ./MacroLibX -s -j --no-print-directory

clean:
	make clean -C ./MacroLibX
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJ_DIR_BNS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) -f $(MLX)
	$(RM) $(NAME)
	$(RM) $(NAME_BNS)

re: fclean all

.PHONY: all clean fclean re
