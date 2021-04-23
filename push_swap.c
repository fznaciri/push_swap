/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/23 15:13:38 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// find min value

int stack_min(stack *a, int *min)
{
    int i;
    int pos;
    
    i = 0;
	while (a)
	{
		if (a->value < a->next->value)
		{
			*min = a->value;
			pos = i; 
		}
		a = a->next;
		i++;
	}
    return (i);
}

//get it to top of stack a (either ra or rra depends on size of a)

//push it to stack b