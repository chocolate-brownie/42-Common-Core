CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_DIR = src
ALGO_DIR = $(SRC_DIR)/algo
SORT_DIR = $(SRC_DIR)/sort
UTILS_DIR = $(SRC_DIR)/utils
OBJ_DIR = obj
INCLUDE_DIR = include
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

ALGO_SRC = $(ALGO_DIR)/push_swap_main.c \
           $(ALGO_DIR)/push_swap_utils.c

SORT_SRC = $(SORT_DIR)/push.c \
           $(SORT_DIR)/rotate.c \
           $(SORT_DIR)/rrotate.c \
           $(SORT_DIR)/swap.c \
           $(SORT_DIR)/tiny_sort.c

UTILS_SRC = $(UTILS_DIR)/error.c \
            $(UTILS_DIR)/split.c \
            $(UTILS_DIR)/stack_init.c \
            $(UTILS_DIR)/stack_utils.c \
            $(SRC_DIR)/main.c

OBJ_FILES = $(ALGO_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(SORT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(UTILS_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

HEADERS = $(INCLUDE_DIR)/push_swap.h

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/algo
	@mkdir -p $(OBJ_DIR)/sort
	@mkdir -p $(OBJ_DIR)/utils

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re