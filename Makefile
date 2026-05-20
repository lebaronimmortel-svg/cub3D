NAME        = cub3D

# --- Directories ---
SRC_DIR     = srcs
OBJ_DIR     = objs
LIBFT_DIR   = srcs/libft
HEADER_DIR  = header

# --- Files ---
SRC         = srcs/main/main.c \


OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)
HEADERS = header/typedef.h header/function.h header/header.h
LIBFT       = $(LIBFT_DIR)/libft.a
CC          = cc
FLAGS       = -Wall -Wextra -Werror -g
RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(HEADER_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
