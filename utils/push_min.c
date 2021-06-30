/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:13:21 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:29:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		p;

	tmp = *a;
	min = tmp->value;
	p = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			p = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (p > 2)
		exec_loop(a, b, "rra", stack_count(*a) - p);
	else
		exec_loop(a, b, "ra", p);
	exec_opr(a, b, 0, "pb");
}
