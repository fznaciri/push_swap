/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:11:42 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:28:05 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	half(t_stack **a, t_stack **b, t_range r, int chunk)
{
	int	l;
	int	n;

	while (is_inrange(*a, r))
	{
		if ((*a)->value >= r.s && (*a)->value <= r.e)
			exec_opr(a, b, chunk, "pb");
		else
			exec_opr(a, b, chunk, "ra");
	}
}

void	first(t_stack **a, t_stack **b, int chunks)
{
	int		l;
	int		chunk;
	t_range	r;

	l = stack_count(*a);
	r.s = 0;
	chunk = 0;
	while (r.s < l)
	{
		r.e = r.s + (l / chunks);
		half(a, b, r, chunk);
		r.s += l / chunks;
		chunk++;
	}
}
