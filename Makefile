# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 01:48:09 by mac               #+#    #+#              #
#    Updated: 2021/06/30 13:13:42 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_BONUS = checker_bonus.c utils/*.c

SRC = push_swap.c utils/*.c

all: $(NAME)

$(NAME):
	@$(C) $(CFLAG) $(SRC) -o $(NAME)

bonus:
	@$(C) $(CFLAG) $(SRC_BONUS) -o checker_bonus

debug:
	@$(C) $(CFLAG) -g $(SRC) -o $(NAME) -fsanitize=address
	@$(C)  $(CFLAG) -g $(SRC_BONUS) -o checker_bonus -fsanitize=address

clean:
	@rm -f $(NAME)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
