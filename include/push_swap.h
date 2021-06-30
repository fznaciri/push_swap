/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:35 by mac               #+#    #+#             */
/*   Updated: 2021/06/24 19:38:47 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack.h"
# include "checker.h"

void	sort3(t_stack **a);
void	sort5(t_stack **a, t_stack **b);
void	sort2(t_stack **a, t_stack **b);
void	sort1(t_stack **a, t_stack **b);
void	exec_loop(t_stack **a, t_stack **b, char *opr, int i);
void	exec_opr(t_stack **a, t_stack **b, int chunk, char *opr);
void	push_min(t_stack **a, t_stack **b);
void	first(t_stack **a, t_stack **b, int chunks);
void	second(t_stack **a, t_stack **b, int chunks);
void	replace(t_stack **a);
int		is_inrange(t_stack *a, t_range r);
t_stack	*copy(t_stack *a);
int		find_position(t_stack *a, int n);
int		is_chunkempty(t_stack *a, int chunk);
int		get_pofhigher(t_stack *a, int chunk);
#endif
