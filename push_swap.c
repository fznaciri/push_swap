/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/05/01 15:54:40 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    exec_opr(stack **a, stack **b, char *opr)
{
    // ft_putendl_fd(opr, 1);
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

stack *copy(stack *a)
{ 
	stack *tmp;
	stack *new;
	
	new = NULL;
	tmp = a;
	while(tmp)
	{
		push(&new, tmp->value);
		tmp = tmp->next;
	}
	return new;
}

int pivot(stack *a)
{
	stack *tmp;
	stack *tmp1;
	stack *c;
	int s;
	int l; 
	c = copy(a);
	tmp1 = c;
	while (tmp1)
	{
		tmp = c;
		while (tmp)
		{
			if (tmp->next && tmp->value > tmp->next->value)
			{
				s = tmp->value;
				tmp->value = tmp->next->value;
				tmp->next->value = s;	
			}
			tmp = tmp->next;	
		}
		tmp1 = tmp1->next;
	}
	l = stack_count(a);
	tmp = c;
	s = 0;
	while (tmp && s < l/2)
	{
		tmp = tmp->next;	
		s++;
	}
	return (tmp->value);
}

int get_last(stack *a)
{
	while (a->next)
		a = a->next;
	return (a->value);
}

void	half(stack **a, stack **b, int p)
{
	stack *tmp;
	int last;
	
	tmp = *a;
	while (tmp)
	{
		last = get_last(tmp);
		// printf("c : %d\n", tmp->value);
		if (tmp->value < p)
			exec_opr(a, b, "pb");
		else if (last < p)
		{
			exec_opr(a, b,"rra");
			exec_opr(a, b,"pb");
		}	
		else
			exec_opr(a, b,"ra");
		tmp = tmp->next;
	}
}
void sort(stack **a, stack **b)
{
	int p;
	
	p = pivot(*a);
	half(a, b, p);
}
// void	sort1(stack **a, stack **b)
// {
// 	int	i;
	
// 	if (!(*a))
// 	{
// 		exec_loop(a, b, "pa", stack_count(*b));	
// 		return;
// 	}
// 	i = stack_min(*a);
// 	push_min(a, b, i);
// 	sort1(a, b);
// }

//psort method 2

// void	sort2(stack **a, stack **b)
// {
// 	int k;
	
// 	while (stack_count(*a) > 0)
// 	{
// 		k = pop(a);
// 		while (stack_count(*b) > 0 && (*b)->value > k)
// 			push_a(a, b);
// 		push(b, k);
// 	}
// 	while (stack_count(*b) > 0)
// 		push_a(a, b);
// }


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
        // print_stack(a, b);
		// printf("%d\n", stack_min(a));
		// printf("%d\n",pivot(a));
		 clear_stack(&a);
		 return 0;
    }
}