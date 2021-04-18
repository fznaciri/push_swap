# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 01:48:09 by mac               #+#    #+#              #
#    Updated: 2021/04/18 02:05:19 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = cheker

D = -g

SRC = cheker.c stack.c


all: $(NAME)

$(NAME):
	@$(C) -g -o $(NAME) checker.c $(SRC)

debug:
	@$(C) -g -o $(NAME) checker.c $(SRC) -fsanitize=address

clean:
	@rm -f $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all