# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:43:44 by mgodawat          #+#    #+#              #
#    Updated: 2025/01/07 12:22:24 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Og -Imlx -Iinclude -Ilib/libft -Ilib/ft_printf -Ilib/gnl
LDFLAGS = -L./mlx -lmlx -Llib/libft -lft -Llib/ft_printf -lftprintf -Llib/gnl -lgnl -lXext -lX11 -lm
NAME    = fractol

SRC_DIR = src
OBJ_DIR = objs
INC_DIR = include
LIBFT_DIR = lib/libft
PRINTF_DIR = lib/ft_printf
GNL_DIR = lib/gnl

SRC_FILES = main.c error_utils.c mlx_utils.c color.c palette.c mandelbrot.c \
			julia.c tricorn.c bs.c parsing_utils.c key_hook.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/libgnl.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux

all: $(MLX_LIB) $(LIBFT) $(PRINTF) $(GNL) $(NAME)
	@echo "✨ Fractol compiled successfully! ✨"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📁 Created objects directory"

$(MLX_LIB):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "🔄 Cloning MLX..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)
	@echo "📚 MLX library ready"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "📚 Libft compiled"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "📚 Printf compiled"

$(GNL):
	@$(MAKE) -C $(GNL_DIR)
	@echo "📚 GNL compiled"

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "🎯 Binary created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Cleaned object files"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(MLX_LIB)
	@echo "🗑️  Full cleanup complete"

cleanmlx:
	@rm -rf $(MLX_DIR)
	@echo "🔄 MLX directory removed"

re: fclean all

.PHONY: all re fclean clean cleanmlx