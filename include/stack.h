/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:47 by mac               #+#    #+#             */
/*   Updated: 2021/06/23 16:26:44 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <stdio.h>

# define MIN_INT -2147483648

typedef struct s_range
{
    int s;
    int e;    
} t_range;

typedef struct s_node {
    int value;
    int chunk; 
    struct s_node *next;
} t_node;


typedef t_node stack;

int     push(stack **s, int value, int chunk);
int     pop(stack **s);
int     stack_count(stack *a);
void    swap(stack **s);
void    sswap(stack **a, stack **b);
void    push_a(stack **a, stack **b, int chunk);
void    push_b(stack **a, stack **b, int chunk);
void    rotate_a(stack **a);
void    rotate_b(stack **a);
void    rotate_ra(stack **a);
void    rotate_rb(stack **a);
void    rotate_rab(stack **a, stack **b);
void    rotate_ab(stack **a, stack **b);
void    print_stack(stack *a, stack *b);
void    clear_stack(stack **s);
int    peek_s(const stack *stack);
void        prints(stack *a);
#endif