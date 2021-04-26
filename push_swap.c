/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/25 13:20:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// sort a stack of 3 elements
void sort3(stack **a)
{
	int a1;
	int a2;
	int a3;

	a1 = (*a)->value;
	a2 = (*a)->next->value;
	a3 = (*a)->next->next->value;
	if (check_sort(*a, NULL))
		return ;
	if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		swap(a);
		rotate_a(a);
	}
	else if (a1 > a2 && a1 < a3 && a2 < a3)
		swap(a);
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		rotate_a(a);
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		swap(a);
		rotate_ra(a);
	}	
	else
		rotate_ra(a);
}

// sort a stack of 5 elements
void sort5(stack **a, stack **b)
{
	push_b(a, b);
	push_b(a, b);
	sort3(a);
}

// find min value

// int stack_min(stack *a, int *min)
// {
//     int i;
//     int pos;
    
//     i = 0;
// 	while (a)
// 	{
// 		if (a->value < a->next->value)
// 		{
// 			*min = a->value;
// 			pos = i; 
// 		}
// 		a = a->next;
// 		i++;
// 	}
//     return (i);
// }

//get it to top of stack a (either ra or rra depends on size of a)

//push it to stack b


int     main(int ac, char **av)
{
    stack     *a;
    stack     *b;
    int         c;

    a = NULL;
    b = NULL;
	if(ac == 1)
        ft_puterror();
    ac--;
    
    if (ac > 1)
    {
        while (ac > 0)
    	{
        	check_errors(av, ac);
        	if(!push(&a, ft_atoi(av[ac])))
            	ft_puterror();
        	ac--;  
    	}
        c = stack_count(a);
        if (c == 3)
            sort3(&a);
        else if (c == 5)
            sort5(&a, &b);
        print_stack(a, b);
		 clear_stack(&a);
		 return 0;
    }
}