/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:57 by mac               #+#    #+#             */
/*   Updated: 2021/06/24 12:01:01 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./checker.h"
# define BUFFER_SIZE 32
int		gnl(int fd, char **line);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t n);
int		ft_atoi(const char *s);
void	ft_opadd_back(t_opr **alst, t_opr *new);
t_opr	*ft_oplast(t_opr *lst);
t_opr	*ft_opnew(char *content);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
#endif
