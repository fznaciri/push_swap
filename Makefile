# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 01:48:09 by mac               #+#    #+#              #
#    Updated: 2021/04/18 14:16:52 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = checker

D = -g

SRC = checker.c stack.c utils/*.c


all: $(NAME)

$(NAME):
	@$(C) -g -o $(NAME) $(SRC)

debug:
	@$(C) -g -o $(NAME) $(SRC) -fsanitize=address

clean:
	@rm -f $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all