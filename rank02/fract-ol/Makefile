NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
MLX_DIR = minilibx-linux

# Source files
SRC_FILES = main.c color_palettes.c color_utils.c error_handling.c \
           extra_fractals.c mandelbrot.c render.c window_controls.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT = $(LIB_DIR)/libft/libft.a
FT_PRINTF = $(LIB_DIR)/printf/libftprintf.a
GNL = $(LIB_DIR)/gnl/libgnl.a
MLX = $(MLX_DIR)/libmlx.a

# Includes
INCLUDES = -I includes -I $(MLX_DIR)
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(OBJ_DIR) $(MLX) $(NAME)

$(OBJ_DIR):
   mkdir -p $(OBJ_DIR)

$(MLX):
   git clone https://github.com/42Paris/minilibx-linux.git || true
   make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL)
   $(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
   $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
   make -C $(LIB_DIR)/libft

$(FT_PRINTF):
   make -C $(LIB_DIR)/printf

$(GNL):
   make -C $(LIB_DIR)/gnl

clean:
   rm -rf $(OBJ_DIR)
   make -C $(LIB_DIR)/libft clean
   make -C $(LIB_DIR)/printf clean
   make -C $(LIB_DIR)/gnl clean
   make -C $(MLX_DIR) clean

fclean: clean
   rm -f $(NAME)
   make -C $(LIB_DIR)/libft fclean
   make -C $(LIB_DIR)/printf fclean
   make -C $(LIB_DIR)/gnl fclean
   rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re