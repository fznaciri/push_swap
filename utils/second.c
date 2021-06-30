/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:38:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:30:34 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	second(t_stack **a, t_stack **b, int chunks)
{
	int	l;
	int	n;

	while (*b && chunks >= 0)
	{
		while (!is_chunkempty(*b, chunks))
		{
			n = get_pofhigher(*b, chunks);
			l = stack_count(*b);
			if (n == 1)
				exec_opr(a, b, 0, "sb");
			else if (n >= (l / 2))
				exec_loop(a, b, "rrb", l - n);
			else
				exec_loop(a, b, "rb", n);
			exec_opr(a, b, chunks, "pa");
		}
		chunks--;
	}
}
