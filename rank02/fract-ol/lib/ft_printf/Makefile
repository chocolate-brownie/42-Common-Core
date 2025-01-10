# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 14:58:48 by mgodawat          #+#    #+#              #
#    Updated: 2024/06/21 16:50:23 by mgodawat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -I./include

AR				=	ar rcs

NAME			=	libftprintf.a

SRCS			=	ft_printf.c \
					src/ft_putchar.c \
					src/ft_putstr.c \
					src/ft_putnbr.c \
					src/ft_putunsigned.c \
					src/ft_puthex.c \
					src/ft_putpointer.c \

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(OBJS:.o=.d)
