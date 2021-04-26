/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:19:44 by mac               #+#    #+#             */
/*   Updated: 2021/04/25 13:05:57 by mac              ###   ########.fr       */
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

// void ft_puterror()
// {
//     ft_putendl_fd("Error", 2);
//     exit(1);    
// }

void process_op(stack **a, stack **b, t_opr *op)
{
	int		i;
	t_opr	*tmp;

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

// void    clear_stack(stack **s)
// {
//     stack *tmp;

//     if (*s)
//     {
//         while (*s)
//         {
//             tmp = *s;
//             *s = tmp->next;
//             free(tmp);
//         }
//     }
// } 

// int     is_dup(char **av, int i)
// {
//     while (av[i + 1])
//     {
//         if (!ft_strcmp(av[i], av[i + 1]))
//             return 1;
//         i++;
//     }
//     return 0;
// }

// void check_errors(char **av, int ac)
// {
//     int i;

//     i = 0;
//     while (av[ac][i])
//     {
//             //av[ac][0] != '+' || av[ac][0] != '-' || 
//         if (!ft_isdigit(av[ac][i]))
//             ft_puterror();
//         i++;
//     }
//     if (is_dup(av, ac) || ft_atoi(av[ac]) >  MAX_INT || ft_atoi(av[ac]) <  MIN_INT)
//         ft_puterror();
// }

// int     check_sort(stack *a, stack *b)
// {
//     stack *tmp;
    
//     if (b)
//         return 0;
//     tmp = a;
//     while (tmp)
//     {
//         if (tmp->next && tmp->value > tmp->next->value)
//             return 0;
//         tmp = tmp->next;
//     }
//     return 1;
        
// }

int main(int ac, char **av)
{
    t_checker arg;
    t_opr *op;
    
    arg.b = NULL;
    if(ac == 1)
        ft_puterror();
    ac--;
    while (ac > 0)
    {
        check_errors(av, ac);
        if(!push(&arg.a, ft_atoi(av[ac])))
            ft_puterror();
        ac--;  
    }
    while (gnl(0, &arg.line) > 0)
    {
        if (!is_op(arg.line))
            ft_puterror();
        op = ft_opnew(arg.line);
        ft_opadd_back(&arg.op, op);
    }
    process_op(&arg.a, &arg.b, arg.op);
    print_stack(arg.a, arg.b);
    if (check_sort(arg.a, arg.b))
        ft_putendl_fd("OK", 1);
    else
        ft_putendl_fd("KO", 2);
    clear_stack(&arg.a);
    clear_stack(&arg.b);
    return 0;
}