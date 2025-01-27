# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:51:17 by mgodawat          #+#    #+#              #
#    Updated: 2025/01/27 23:15:41 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror -pthread
NAME	= philo

SRC_DIR	= src
INC_DIR	= include
OBJ_DIR	= obj

SRC		= main.c utils.c parsing.c struct_init.c pthread_utils.c \
		struct_init.c debug.c\

BONUS_SRC	= bonus/main.c

SRCS	= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "philo compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Full cleanup done"

re: fclean all

.PHONY: all clean fclean re
