/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/26 17:09:16 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    exec_opr(stack **a, stack **b, char *opr)
{
    ft_putendl_fd(opr, 1);
    do_opr(a, b, opr);
}


void    exec_loop(stack **a, stack **b, char *opr, int i)
{
    while (i > 0)
    {
        exec_opr(a, b, opr);
        i--;
    }
}

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

// find position of an elmt of b in a
int find(stack *a, int n)
{
	stack *tmp;
	int i;
	
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > n)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

// sort a stack of 5 elements
// void sort5(stack **a, stack **b)
// {
// 	int i;
// 	int size;
	
// 	size = stack_count(*a);
// 	push_b(a, b);
// 	push_b(a, b);
// 	sort3(a);
// 	while (b)
// 	{
// 		i = find(*a, peak_s(*b));
// 		if (i)
		
// 	}
	
// }

// find min value

int stack_min(stack *a)
{
	stack *tmp;
    int i;
    int pos;
    int min;
	
    i = 1;
	tmp = a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value <= min)
		{
			min = tmp->value;
			pos = i; 
		}
		tmp = tmp->next;
		i++;
	}
    return (pos);
}

//get it to top of stack a (either ra or rra depends on size of a)
void	push_min(stack **a, stack **b, int i)
{
	int len;

	len = stack_count(*a);
	// print_stack(*a, *b);
	// printf("i : %d\t\t count : %d\n", i, len);
	if (i < len / 2)
		exec_loop(a, b, "ra", i - 1);
	else
		exec_loop(a, b, "rra", len - i + 1);
	// printf("%d\n", peek_s(*a));
	exec_opr(a, b, "pb");
}

void	sort(stack **a, stack **b)
{
	int	i;
	
	if (!(*a))
	{
		exec_loop(a, b, "pa", stack_count(*b));	
		return;
	}
	i = stack_min(*a);
	push_min(a, b, i);
	sort(a, b);
}

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
        // else if (c == 5)
        //     sort5(&a, &b);
		else
			sort(&a, &b);
		// printf("%d\n", stack_min(a));
        print_stack(a, b);
		 clear_stack(&a);
		 return 0;
    }
}