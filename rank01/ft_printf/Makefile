# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 13:10:53 by mgodawat          #+#    #+#              #
#    Updated: 2024/06/24 19:45:23 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include
AR = ar rcs
NAME = libftprintf.a

SRC =	ft_printf.c \
		src/ft_putstr.c \
		src/ft_putchar.c \
		src/ft_putpointer.c \
		src/ft_putnbr.c \
		src/ft_puthexnbr.c \
		src/ft_putnbrunsigned.c \

# objects files
OBJS = $(SRC:.c=.o)

# target
all: $(NAME)

# build static library
$(NAME): $(OBJS)
	$(AR) $@ $^

# clean objs files
clean:
	rm -f $(OBJS)
# clean objs files and .a file
fclean: clean
	rm -f $(NAME)
# clean everything and rebuild again
re: fclean all


