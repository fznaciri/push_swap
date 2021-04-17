#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <stdio.h>

# define MIN_INT -2147483648

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;


typedef t_node stack;

int     push(stack **s, int value);
int     pop(stack **s);
int     stack_count(stack *a);
void    swap(stack **s);
void    sswap(stack **a, stack **b);
void    push_a(stack **a, stack **b);
void    push_b(stack **a, stack **b);
void    rotate_a(stack **a);
void    rotate_b(stack **a);
void    rotate_ra(stack **a);
void    rotate_rb(stack **a);
void    rotate_rab(stack **a, stack **b);
void    rotate_ab(stack **a, stack **b);
void    print_stack(stack *s);

#endif