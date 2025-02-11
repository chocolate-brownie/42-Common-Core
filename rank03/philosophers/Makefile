# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:51:17 by mgodawat          #+#    #+#              #
#    Updated: 2025/02/11 02:44:39 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## WARNING: Remove GCC and CC without -g, and remove the debug.c 

CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror -pthread
NAME	= philo

SRC_DIR	= src
INC_DIR	= include
OBJ_DIR	= obj

SRC		= main.c init.c utils.c pthread_utils.c debug.c create_phils.c /
		routine.c routine_utils.c cleanup.c 

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
