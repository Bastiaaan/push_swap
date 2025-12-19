NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
      ft_calloc.c \
      ft_isalnum.c \
      ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
      ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstlast.c \
	  ft_lstnew.c \
	  ft_lstpop.c \
	  ft_lstsize.c \
	  ft_memchr.c \
	  ft_memcmp.c \
      ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c

OBJ = $(SRC:.c=.o)
HEADER_FILE = libft.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

CC_DEBUG = gcc
CC_DEBUG_FLAG = -g -Wall -Wextra

# COLOR CODES BELOW
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling ft-files...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Compilation of $(NAME) succeeded.$(RESET)"

%.o: %.c $(HEADER_FILE)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Removing all .o files...$(RESET)"
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "$(GREEN)All .o files removed.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Deleting $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed.$(RESET)"

re: fclean all
	@echo "$(GREEN)Compilation completed.$(RESET)"
