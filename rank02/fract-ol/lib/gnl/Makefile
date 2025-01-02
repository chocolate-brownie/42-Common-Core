NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I .

SRC = get_next_line.c get_next_line_utils.c get_next_line_bonus.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re