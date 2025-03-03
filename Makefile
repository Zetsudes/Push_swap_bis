# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 09:48:42 by zamohame          #+#    #+#              #
#    Updated: 2025/02/10 10:44:23 by zamohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ../greg_lib

LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fPIE

SRC = push_swap.c \
      parsing.c \
	  sorting_utils.c \
	  utils.c \
	  sort.c \
      push.c \
      swap.c \
      rotate.c \
      reverse_rotate.c \
	  handle_argv.c \

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
