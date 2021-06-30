/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:39:40 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:13:07 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_inrange(t_stack *a, t_range r)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value >= r.s && tmp->value <= r.e)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
