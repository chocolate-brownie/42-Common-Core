NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
MLX = minilibx-linux
MLX_FLAGS = -L$(MLX) -lmlx_Linux -lXext -lX11 -lm -lz

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/core/open_window.c \
		$(SRC_DIR)/core/close_window.c \
    #   $(SRC_DIR)/core/cleanup.c \
    #   $(SRC_DIR)/utils/error.c \
    #   $(SRC_DIR)/utils/parsing.c \
    #   $(SRC_DIR)/graphics/render.c \
    #   $(SRC_DIR)/graphics/window.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDES = -I$(INC_DIR) -I$(MLX)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re