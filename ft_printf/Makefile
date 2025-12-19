
NAME := libftprintf.a

SRC := ft_printf.c \
	   types.c \
	   types1.c \
	   ft_printf_utils.c

HEADER_FILE = ft_printf.h

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ := $(SRC:.c=.o)

CC := cc
CC_FLAGS := -Wall -Werror -Wextra

#Color declaration below;
BLUE := \033[0;34m
GREEN := \033[0,32m
RED := \033[0;31m
RESET := \033[0m
YELLOW := \033[1;33m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(YELLOW)Compiling all .c files...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Compilation of $(NAME) successful$(RESET)"

%.o: %.c $(HEADER_FILE)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(YELLOW)Removing all the .o files$(RESET)"
	$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "$(GREEN)All o. files removed$(RESET)"

fclean: clean
	@echo "$(YELLOW)Deleting $(NAME)...$(RESET)"
	$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed$(RESET)"

re: fclean all
	@echo "$(GREEN)Compilation completed.$(RESET)"