# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 09:46:23 by mgodawat          #+#    #+#              #
#    Updated: 2025/01/07 09:46:30 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
HEADERS = get_next_line.h get_next_line_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re