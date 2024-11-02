NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs
INCDIR = includes

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:.c=.o)

all: $(LIBFT_LIB) $(NAME)

# Custom message for starting build process
$(NAME): $(OBJ)
	@echo "🔨 [Building] Linking the $(NAME) executable..."
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFT_DIR)/include -o $(NAME) $(OBJ) $(LIBFT_LIB)
	@echo "✅ [Success] $(NAME) executable created."

# Build libft by calling its own Makefile with a custom message
$(LIBFT_LIB):
	@echo "🔧 [Building] Compiling libft library..."
	$(MAKE) -C $(LIBFT_DIR)
	@echo "✅ [Success] libft library built."

# Rule to compile each .c file into a .o file with a custom message
%.o: %.c
	@echo "🛠️  [Compiling] $<"
	$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFT_DIR)/include -c $< -o $@

# Clean object files and libft objects with a custom message
clean:
	@echo "🧹 [Cleaning] Removing object files..."
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "✅ [Clean] Object files removed."

# Clean all files including the executable and libft with a custom message
fclean: clean
	@echo "🧹 [Cleaning] Removing $(NAME) executable and libft library..."
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "✅ [Clean] $(NAME) executable and libft library removed."

# Recompile everything from scratch with a custom message
re: fclean all

# Phony targets to avoid confusion with file names
.PHONY: all clean fclean re

