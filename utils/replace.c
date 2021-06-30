/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:37:28 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:27:31 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	replace(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*c;

	c = copy(*a);
	tmp = *a;
	while (tmp)
	{
		tmp->value = find_position(c, tmp->value);
		tmp = tmp->next;
	}
	clear_stack(&c);
}
