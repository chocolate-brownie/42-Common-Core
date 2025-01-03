# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 22:17:10 by mgodawat          #+#    #+#              #
#    Updated: 2025/01/03 03:58:54 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Og -Imlx -Iinclude -Ilib/libft
LDFLAGS = -L./mlx -lmlx -Llib/libft -lft -lXext -lX11 -lm
NAME    = fractol

SRC_DIR = src
OBJ_DIR = objs
INC_DIR = include
LIBFT_DIR = lib/libft

SRC_FILES =	main.c \
			valid.c \
			init_mlx.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux

all: $(MLX_LIB) $(LIBFT) $(NAME)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning minilibx repository..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(MLX_LIB)
	@echo "Cleaned executables and libraries"

cleanmlx:
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all re fclean clean cleanmlx