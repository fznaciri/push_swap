/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:21:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/18 14:04:39 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc((n * sizeof(char)) + 1)))
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
