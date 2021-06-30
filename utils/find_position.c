/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:10:49 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:11:04 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_position(t_stack *a, int n)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < n)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
