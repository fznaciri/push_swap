/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:13:37 by mac               #+#    #+#             */
/*   Updated: 2021/04/18 11:13:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int		ft_atoi(const char *s)
{
	int		i;
	size_t	n;
	int		sign;

	sign = 1;
	i = 0;
	n = 0;
	while ((s[i] >= 9 && s[i] <= 16) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		n = n * 10 + s[i] - '0';
		if (n > 9223372036854775807)
			return ((sign > 0) ? -1 : 0);
		i++;
	}
	return (n * sign);
}