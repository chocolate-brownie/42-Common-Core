NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS_DIR = src/
OBJS_DIR = obj/
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDE_DIR = include/

# Automatically include all .c files from specified directories
SRCS = $(wildcard $(SRCS_DIR)*.c) \
       $(wildcard $(SRCS_DIR)operations/*.c) \
       $(wildcard $(SRCS_DIR)utils/*.c)

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

# Colors 🌈
RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
CYAN = \033[36m

all: $(NAME)

# Compiling Push_swap 🚀
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✅ Build completed: $(NAME)$(RESET)"

# Compiling objects 📦
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@
	@echo "$(BLUE)🔨 Compiling $< $(RESET)"

# Build Libft 📚
$(LIBFT):
	@echo "$(CYAN)📦 Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

# Clean up 🧹
clean:
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)🧹 Objects cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "$(YELLOW)🧹 All cleaned$(RESET)"

# Rebuild ♻️
re: fclean all

# Directory creation helper 🗂️
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

.PHONY: all clean fclean re