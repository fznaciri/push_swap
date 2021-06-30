/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pofhigher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:42:29 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:12:14 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pofhigher(t_stack *a, int chunk)
{
	t_stack	*tmp;
	int		max;
	int		i;
	int		p;

	tmp = a;
	max = tmp->value;
	p = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value > max && tmp->chunk == chunk)
		{
			max = tmp->value;
			p = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (p);
}
