/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/30 15:47:21 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sort3(t_stack **a)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = (*a)->value;
	a2 = (*a)->next->value;
	a3 = (*a)->next->next->value;
	if (check_sort(*a, NULL))
		return ;
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

void	sort5(t_stack **a, t_stack **b)
{
	push_min(a, b);
	push_min(a, b);
	sort3(a);
	exec_opr(a, b, 0, "pa");
	exec_opr(a, b, 0, "pa");
}

void	sort(t_stack **a, t_stack **b)
{
	int	chunks;
	int	l;

	l = stack_count(*a);
	if (l <= 100)
		chunks = 5;
	else
		chunks = 11;
	if (l == 3)
		sort3(a);
	else if (l == 5)
		sort5(a, b);
	else
	{
		first(a, b, chunks);
		second(a, b, chunks);
	}
}
void        prints(t_stack *a)
{
    t_stack *tmp1;

    tmp1  = a;
    printf("---------------\n");
    while (tmp1)
    {
        printf("value : %d\t\tchunk : %d\n", tmp1->value, tmp1->chunk);
        tmp1 = tmp1->next;
    }
    printf("---------------\n");
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		ft_puterror();
	ac--;
	if (ac > 1)
	{
		while (ac > 0)
		{
			check_errors(av, ac);
			if (!push(&a, ft_atoi(av[ac]), 0))
				ft_puterror();
			ac--;
		}
		if (check_sort(a, NULL))
			return (0);
		replace(&a);
		sort(&a, &b);
		clear_stack(&a);
	}
	return (0);
}
