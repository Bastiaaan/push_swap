# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 02:46:26 by brogaar           #+#    #+#              #
#    Updated: 2026/01/04 20:37:43 by brogaar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap.a
DEBUG_NAME = push_swap.test

CC     = cc
CFLAGS = -Wall -Wextra -Werror -g

CC_DEBUG = gcc
CC_DEBUG_FLAG = -g -Wall -Wextra

FT_PRINTF_DIR = ./ft_printf
LIBFT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT  = $(LIBFT_DIR)/libft.a

SRCS   = main.c \
		 src/push_swap.c \
		 src/utils.c \
		 src/algorithm.c \
		 src/actions_a.c \
		 src/actions_b.c \
		 src/actions_dd.c \
		 src/sorting_utils.c

OBJS   = $(SRCS:.c=.o)

#Color declaration below
BLUE := \033[0;34m
GREEN := \033[0;32m
PURPLE := \033[0;35m
RED := \033[0;31m
RESET := \033[0m
YELLOW := \033[1;33m

#BOLD versions;
BLD_BLUE := \033[1;34m
BLD_GREEN := \033[1,32m
BLD_PURPLE := \033[1;35m
BLD_RED := \033[1;31m
BLD_RESET := \033[0m
BLD_YELLOW := \033[1;33m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

debug: $(DEBUG_NAME)
	@echo "$(BLD_PURPLE)Debugging mode$(RESET)"

$(DEBUG_NAME): $(OBJS) $(LIBFT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PRINTF) $(LIBFT) -o $(DEBUG_NAME)

%.o: %.c
	$(CC_DEBUG) $(CC_DEBUG_FLAG) -c $< -o $@
	
	@echo "$(BLD_PURPLE)$(DEBUG_NAME)$(RESET)$(PURPLE) is now ready$(RESET)"
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME)
	rm -f $(DEBUG_NAME)

re: fclean all

.PHONY: all clean fclean re