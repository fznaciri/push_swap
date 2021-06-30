/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:29:35 by mac               #+#    #+#             */
/*   Updated: 2021/06/24 19:28:27 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

char	*ft_checkerror(int fd, char **buff)
{
	if (!(BUFFER_SIZE >= 1) || (read(fd, *buff, 0) < 0))
		return (NULL);
	return (*buff);
}

int	ft_readline(int fd, char **str)
{
	char	*tmp;
	char	*buff;
	int		n;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff || !ft_checkerror(fd, &buff))
	{
		free(buff);
		return (-1);
	}
	n = read (fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		buff[n] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (n);
}

int	clean_gnl(char **line, char **str, int n)
{
	if (!n && *str)
	{
		*line = ft_strdup(*str);
		free(*str);
		str = NULL;
		return (1);
	}
	return (0);
}

int	gnl(int fd, char **line)
{
	static char	*str;
	char		*tmp;
	char		*s;
	int			n;

	n = ft_readline(fd, &str);
	if (n < 0 || !line)
		return (-1);
	s = ft_strchr(str, '\n');
	if (s)
	{
		*line = ft_strndup(str, s - str);
		tmp = str;
		str = ft_strdup(s + 1);
		free(tmp);
		return (1);
	}
	if (clean_gnl(line, &str, n))
		return (0);
	*line = ft_strdup("");
	return (0);
}
