# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 01:48:09 by mac               #+#    #+#              #
#    Updated: 2021/04/26 16:29:54 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_C = checker.c stack.c utils/*.c

SRC_P = push_swap.c stack.c utils/*.c

all: $(NAME)

$(NAME):
	@$(C) $(CFLAG) $(SRC_P) -o $(NAME)
	@$(C) $(CFLAG) $(SRC_C) -o checker

debug:
	@$(C) -g -o $(NAME) $(SRC_P) -fsanitize=address

clean:
	@rm -f $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all