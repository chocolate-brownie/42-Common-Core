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
		$(SRC_DIR)/core/open_window.c \
		$(SRC_DIR)/core/close_window.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDES = -I$(INC_DIR) -I$(MLX) -I$(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re