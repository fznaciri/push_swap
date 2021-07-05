# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 01:48:09 by mac               #+#    #+#              #
#    Updated: 2021/07/05 15:35:15 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_BONUS = checker_bonus.c \
			utils/check_errors.c \
			utils/check_sort.c \
			utils/copy.c \
			utils/do_opr.c \
			utils/exec_loop.c \
			utils/exec_opr.c \
			utils/find_position.c \
			utils/first.c \
			utils/ft_atoi.c \
			utils/ft_isdigit.c \
			utils/ft_opadd_back.c \
			utils/ft_oplast.c \
			utils/ft_opnew.c \
			utils/ft_putendl_fd.c \
			utils/ft_puterror.c \
			utils/ft_strchr.c \
			utils/ft_strcmp.c \
			utils/ft_strdup.c \
			utils/ft_strjoin.c \
			utils/ft_strlen.c \
			utils/ft_strndup.c \
			utils/get_pofhigher.c \
			utils/gnl.c \
			utils/is_chunkempty.c \
			utils/is_dup.c \
			utils/is_inrange.c \
			utils/operations.c \
			utils/operations2.c \
			utils/push_min.c \
			utils/replace.c \
			utils/second.c \
			utils/stack.c

SRC = 	push_swap.c \
		utils/check_errors.c \
		utils/check_sort.c \
		utils/copy.c \
		utils/do_opr.c \
		utils/exec_loop.c \
		utils/exec_opr.c \
		utils/find_position.c \
		utils/first.c \
		utils/ft_atoi.c \
		utils/ft_isdigit.c \
		utils/ft_opadd_back.c \
		utils/ft_oplast.c \
		utils/ft_opnew.c \
		utils/ft_putendl_fd.c \
		utils/ft_puterror.c \
		utils/ft_strchr.c \
		utils/ft_strcmp.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_strndup.c \
		utils/get_pofhigher.c \
		utils/gnl.c \
		utils/is_chunkempty.c \
		utils/is_dup.c \
		utils/is_inrange.c \
		utils/operations.c \
		utils/operations2.c \
		utils/push_min.c \
		utils/replace.c \
		utils/second.c \
		utils/stack.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(C) $(CFLAG) $(SRC) -o $(NAME)

bonus:
	@$(C) $(CFLAG) $(SRC_BONUS) -o checker_bonus

clean:
	@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME) checker_bonus

re: fclean all

.PHONY: re fclean clean all
