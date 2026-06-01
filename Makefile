NAME        = cub3D

# --- Directories ---
SRC_DIR     = srcs
OBJ_DIR     = objs
LIBFT_DIR   = srcs/libft
HEADER_DIR  = header
MLX 		= ./MacroLibX/libmlx.so

# --- Files ---
SRC         =	srcs/main/main.c \
				srcs/main/init.c \
				srcs/parser/parser.c \
				srcs/parser/utils.c \
				srcs/parser/parser_utils.c \
				srcs/parser/suround_diff.c \
				srcs/parser/main_parser.c \
				srcs/parser/create_map.c \
				srcs/parser/my_ft_split.c \
				srcs/parser/check_infos.c \
				srcs/raycasting/raycasting.c \
				srcs/utils/utils.c \
				srcs/event/event.c \
				srcs/free/free_game.c \


OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)
HEADERS 	= header/typedef.h header/function.h header/header.h
LIBFT       = $(LIBFT_DIR)/libft.a
CC          = cc
FLAGS       = -Wall -Wextra -Werror -g
RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $^ -lSDL2 -lXext -lX11 -lm -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C ./MacroLibX -s -j --no-print-directory

clean:
	make clean -C ./MacroLibX
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) -f $(MLX)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
