/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/23 17:13:40 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    exec_opr(stack **a, stack **b, int chunk, char *opr)
{
    ft_putendl_fd(opr, 1);
    do_opr(a, b, chunk, opr);
}


void    exec_loop(stack **a, stack **b, char *opr, int i)
{
    while (i > 0)
    {
        exec_opr(a, b,0, opr);
        i--;
    }
}
int	is_chunkempty(stack *a, int chunk)
{
	stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
int	get_pofhigher(stack *a, int chunk)
{
	stack	*tmp;
	int		max;
	int		i;
	int		p;

	tmp = a;
	max = tmp->value;
	p = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value > max && tmp->chunk == chunk)
		{
			max = tmp->value;
			p = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (p);
}

void push_min(stack **a, stack **b)
{
	stack	*tmp;
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
 
// sort a stack of 3 elements
void sort3(stack **a)
{
	int a1;
	int a2;
	int a3;

	a1 = (*a)->value;
	a2 = (*a)->next->value;
	a3 = (*a)->next->next->value;
	if (a1 < a2 && a1 < a3 && a2 > a3)
	{
		exec_opr(a, NULL, 0, "sa");
		exec_opr(a, NULL, 0, "ra");
	}
	else if (a1 > a2 && a1 < a3 && a2 < a3)
		exec_opr(a, NULL, 0, "sa");
	else if (a1 > a2 && a1 > a3 && a2 < a3)
		exec_opr(a, NULL, 0, "ra");
	else if (a1 > a2 && a1 > a3 && a2 > a3)
	{
		exec_opr(a, NULL, 0, "sa");
		exec_opr(a, NULL, 0, "rra");
	}	
	else
		exec_opr(a, NULL, 0, "rra");
}


int find_position(stack *a, int n)
{
	stack *tmp;
	int i;
	
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < n)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

// sort a stack of 5 elements
void sort5(stack **a, stack **b)
{
	push_min(a, b);
	push_min(a, b);
	sort3(a);
	exec_opr(a, b, 0, "pa");
	exec_opr(a, b, 0, "pa");
}


stack *copy(stack *a)
{ 
	stack *tmp;
	stack *new;
	
	new = NULL;
	tmp = a;
	while(tmp)
	{
		push(&new, tmp->value, tmp->chunk);
		tmp = tmp->next;
	}
	return new;
}

int is_inrange(stack *a, t_range r)
{
	stack *tmp;
	
	tmp = a;
	while (tmp)
	{
		if (tmp->value >= r.s && tmp->value <= r.e)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void	half(stack **a, stack **b, t_range r, int chunk)
{
	int l;
	int n;

	while (is_inrange(*a, r))
	{
		if ((*a)->value >= r.s && (*a)->value <= r.e)
			exec_opr(a, b, chunk, "pb");
		else
			exec_opr(a, b, chunk, "ra");
	}
}

void first(stack **a, stack **b, int chunks)
{
	int l;
	int chunk;
	t_range r;
	
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

void second(stack **a, stack **b, int chunks)
{
	int l;
	int n;

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
void	sort(stack **a, stack **b)
{
	int chunks;
	int l;
	
	l = stack_count(*a);
	if (l <= 100)
		chunks = 5;
	else 
		chunks = 11;
	//prints(*b);
	first(a, b, chunks);
	//prints(*b);
	second(a, b, chunks);
	//print_stack(*a, *b);
}

void replace(stack **a)
{
	stack *tmp;
	stack *c;
	
	c = copy(*a);
	tmp = *a;
	while (tmp)
	{
		tmp->value = find_position(c, tmp->value);
		tmp = tmp->next;
	}
	clear_stack(&c);
}

int     main(int ac, char **av)
{
    stack     *a;
    stack     *b;
    int         c;
	int i;
	
	i = 0;
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
        	if(!push(&a, ft_atoi(av[ac]), 0))
            	ft_puterror();
        	ac--;  
    	}
		if (check_sort(a, NULL))
			return 0;
		replace(&a);
        c = stack_count(a);
        if (c == 3)
            sort3(&a);
        else if (c == 5)
            sort5(&a, &b);
		else
			sort(&a, &b);
		clear_stack(&a);
    }
	while (1)
		;
	return 0;
}