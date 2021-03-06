/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:21 by mac               #+#    #+#             */
/*   Updated: 2021/06/30 13:29:02 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "stack.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFFER_SIZE 32

typedef struct s_opr
{
	char			*op;
	struct s_opr	*next;
}					t_opr;

typedef struct s_checker
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_opr	*op;
}			t_checker;

int		is_op(char *s);
void	process_op(t_stack **a, t_stack **b, t_opr *op);
int		gnl(int fd, char **line);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t n);
long	ft_atoi(const char *s);
void	ft_opadd_back(t_opr **alst, t_opr *new);
t_opr	*ft_oplast(t_opr *lst);
t_opr	*ft_opnew(char *content);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
void	ft_puterror(void);
int		is_dup(char **av, int i);
void	check_errors(char **av, int ac);
int		check_sort(t_stack *a, t_stack *b);
void	do_opr(t_stack **a, t_stack **b, int chunk, char *opr);
void	get_op(t_checker *arg, t_opr *op);
void	check_r(t_stack **a, t_stack **b, t_opr *op);
#endif
