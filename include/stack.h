/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:47 by mac               #+#    #+#             */
/*   Updated: 2021/06/24 19:25:16 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdio.h>
# define MIN_INT -2147483648

typedef struct s_range
{
	int	s;
	int	e;
}		t_range;

typedef struct s_stack
{
	int				value;
	int				chunk;
	struct s_stack	*next;
}					t_stack;

int		push(t_stack **s, int value, int chunk);
int		pop(t_stack **s);
int		stack_count(t_stack *a);
void	swap(t_stack **s);
void	sswap(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b, int chunk);
void	push_b(t_stack **a, t_stack **b, int chunk);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **a);
void	rotate_ra(t_stack **a);
void	rotate_rb(t_stack **a);
void	rotate_rab(t_stack **a, t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b);
void	clear_stack(t_stack **s);
int		peek_s(const t_stack *t_stack);
void	prints(t_stack *a);
#endif
