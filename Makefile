# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brogaar <brogaar@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 02:46:26 by brogaar           #+#    #+#              #
#    Updated: 2025/12/07 05:39:30 by brogaar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Wextra -Werror
NAME   = push_swap.a
FT_PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
LIBFT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT  = $(LIBFT_DIR)/libft.a

SRCS   = main.c \
		 push_swap.c \
		 utils.c 

OBJS   = $(SRCS:.c=.o)

HEADER_FILE = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re