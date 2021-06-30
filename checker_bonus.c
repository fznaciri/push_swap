/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:19:44 by mac               #+#    #+#             */
/*   Updated: 2021/06/30 13:29:47 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

int	is_op(char *s)
{
	if (!ft_strcmp(s, "sa"))
		return (1);
	else if (!ft_strcmp(s, "sb"))
		return (1);
	else if (!ft_strcmp(s, "ss"))
		return (1);
	else if (!ft_strcmp(s, "pa"))
		return (1);
	else if (!ft_strcmp(s, "pb"))
		return (1);
	else if (!ft_strcmp(s, "ra"))
		return (1);
	else if (!ft_strcmp(s, "rb"))
		return (1);
	else if (!ft_strcmp(s, "rr"))
		return (1);
	else if (!ft_strcmp(s, "rra"))
		return (1);
	else if (!ft_strcmp(s, "rrb"))
		return (1);
	else if (!ft_strcmp(s, "rrr"))
		return (1);
	return (0);
}

void	check_r(t_stack **a, t_stack **b, t_opr *op)
{
	if (!ft_strcmp(op->op, "ra"))
		rotate_a(a);
	else if (!ft_strcmp(op->op, "rb"))
		rotate_b(b);
	else if (!ft_strcmp(op->op, "rr"))
		rotate_ab(a, b);
	else if (!ft_strcmp(op->op, "rra"))
		rotate_ra(a);
	else if (!ft_strcmp(op->op, "rrb"))
		rotate_ra(b);
	else if (!ft_strcmp(op->op, "rrr"))
		rotate_rab(a, b);
	else
		ft_puterror();
}

void	process_op(t_stack **a, t_stack **b, t_opr *op)
{
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
			push_a(a, b, 0);
		else if (!ft_strcmp(tmp->op, "pb"))
			push_b(a, b, 0);
		else
			check_r(a, b, tmp);
		tmp = tmp->next;
	}
}

void	get_op(t_checker *arg, t_opr *op)
{
	while (gnl(0, &(arg->line)) > 0)
	{
		if (!is_op(arg->line))
			ft_puterror();
		op = ft_opnew(arg->line);
		ft_opadd_back(&arg->op, op);
	}
}

int	main(int ac, char **av)
{
	t_checker	arg;
	t_opr		*op;

	arg.b = NULL;
	if (ac == 1)
		return (0);
	ac--;
	while (ac > 0)
	{
		check_errors(av, ac);
		if (!push(&arg.a, ft_atoi(av[ac]), 0))
			ft_puterror();
		ac--;
	}
	get_op(&arg, op);
	process_op(&arg.a, &arg.b, arg.op);
	if (check_sort(arg.a, arg.b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 2);
	clear_stack(&arg.a);
	clear_stack(&arg.b);
	return (0);
}
