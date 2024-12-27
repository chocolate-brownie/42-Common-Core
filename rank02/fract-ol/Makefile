NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_PATH = libft
MLX = minilibx-linux
MLX_FLAGS = -L$(MLX) -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/core/ctrl_args.c \
		$(SRC_DIR)/utils/clean.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDES = -I$(INC_DIR) -I$(MLX) -I$(LIBFT_PATH)

$(NAME): $(MLX)/libmlx_Linux.a $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(MLX)/libmlx_Linux.a:
	@if [ ! -d "$(MLX)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX); \
	fi
	@make -C $(MLX)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@if [ -d "$(MLX)" ]; then \
		make -C $(MLX) clean; \
	fi
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@if [ -d "$(MLX)" ]; then \
		rm -rf $(MLX); \
	fi
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
