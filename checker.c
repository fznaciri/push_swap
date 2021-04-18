/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:19:44 by mac               #+#    #+#             */
/*   Updated: 2021/04/18 11:53:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

int is_op(char *s)
{
    if (!ft_strcmp(s, "sa"))
        return 1;
    else if (!ft_strcmp(s, "sb"))
        return 1;
    else if (!ft_strcmp(s, "ss"))
        return 1;
    else if (!ft_strcmp(s, "pa"))
        return 1;
    else if (!ft_strcmp(s, "pb"))
        return 1;
    else if (!ft_strcmp(s, "ra"))
        return 1;
    else if (!ft_strcmp(s, "rb"))
        return 1;
    else if (!ft_strcmp(s, "rr"))
        return 1;
    else if (!ft_strcmp(s, "rra"))
        return 1;
    else if (!ft_strcmp(s, "rrb"))
        return 1;
    else if (!ft_strcmp(s, "rrr"))
        return 1;  
    return 0;  
}

void process_op(stack **a, stack **b, t_op *op)
{
	int		i;
	t_op	*tmp;

	tmp = op;
	while (tmp)
	{
		if (!ft_strcmp(tmp->op, "sa"))
            swap(a);
        else if (!ft_strcmp(tmp->op, "sb"))
			swap(b);	
        else if (!ft_strcmp(tmp->op, "ss"))
			sswap(a, b);
		else if (!ft_strcmp(tmp->op, "pa"))
            push_a(a, b);
        else if (!ft_strcmp(tmp->op, "pb"))
			push_b(a, b);
		else if (!ft_strcmp(tmp->op, "ra"))
            rotate_a(a);
        else if (!ft_strcmp(tmp->op, "rb"))
            rotate_b(b);
		else if	(!ft_strcmp(tmp->op, "rr"))
			rotate_ab(a, b);
		else if (!ft_strcmp(tmp->op, "rra"))
			rotate_ra(a);
        else if (!ft_strcmp(tmp->op, "rrb"))
			rotate_ra(b);
        else if (!ft_strcmp(tmp->op, "rrr"))
			rotate_rab(a, b);
        else
            ft_puterror();
		tmp = tmp->next;
	}
}


int main(int ac, char **av)
{
    t_checker arg;
    t_op *op;
    int i;

    i = 0;
    arg.b = NULL;
    if(ac == 1)
        exit(1);
    while (gnl(0, &arg.line) > 0)
    {
        if (!is_op(arg.line))
            exit(1);
        op = ft_opnew(arg.line);
        ft_opaddback(&arg.op, op);
    }
    while (i < ac)
    {
        if (!ft_isduplicated(av, ft_atoi(av[ac])))
        {
            if(!push(&arg.a, ft_atoi(av[ac])))
            exit(1);
        }
        i++;  
    }
    process_op(&arg.a, &arg.b, arg.op);
    check_sort(arg.a) ? ft_putendl("OK") : ft_putendl("KO");
    clear_stack(&arg.a);
    clear_stack(&arg.b);
    return 0;
}