/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:09:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:09:16 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*copy(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*new;

	new = NULL;
	tmp = a;
	while (tmp)
	{
		push(&new, tmp->value, tmp->chunk);
		tmp = tmp->next;
	}
	return (new);
}
