/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:00:12 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/17 15:06:11 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

int push(stack **s, int value)
{
    stack *new;

    new = malloc(sizeof(stack));
    if (!new)
        return (0);
    new->value = value;
    new->next = *s;
    *s = new;
    return (1);
}

int pop(stack **s)
{
    int result;
    stack *tmp;
    
    if (*s== NULL)
        return (MIN_INT);
    tmp = *s;
    result = tmp->value;
    *s = tmp->next;
    //free(tmp);
    return (result);
}

int     stack_count(stack *a)
{
    stack *tmp;
    int c;

    tmp = a;
    c = 0;
    while (tmp)
    {
        c++;
        tmp = tmp->next;
    }
    return c;
}

void    swap(stack **s)
{
    int t1, t2;

    if (stack_count(*s) > 1)
    {
        t1 = pop(s);
        t2 = pop(s);
        push(s, t1);
        push(s, t2);
    }
}

void    sswap(stack **a, stack **b)
{
    swap(a);
    swap(b);
}

void    push_a(stack **a, stack **b)
{
    int  t;
    
    if (stack_count(*b) >= 1)
    {
        t = pop(b);
        push(a, t);
    }
}

void    push_b(stack **a, stack **b)
{
    int  t;
    
    if (stack_count(*a) >= 1)
    {
        t = pop(a);
        push(b, t);
    }
}

void    rotate_a(stack **a)
{
    int t;
    stack *tmp;
    stack *new;

    if (stack_count(*a) > 1)
    {
        t = pop(a);
        tmp = *a;
        while (tmp)
        {
            if (!tmp->next)
            {
                new = malloc(sizeof(t_node));
                new->value = t;
                new->next = NULL;
                tmp->next = new;
                break ;
            }
            tmp = tmp->next;
        }
    }
}

void    rotate_b(stack **a)
{
    int t;
    stack *tmp;
    stack *new;

    if (stack_count(*a) > 1)
    {
        t = pop(a);
        tmp = *a;
        while (tmp)
        {
            if (!tmp->next)
            {
                new = malloc(sizeof(t_node));
                new->value = t;
                new->next = NULL;
                tmp->next = new;
                break ;
            }
            tmp = tmp->next;
        }
    }
}

void    rotate_ra(stack **a)
{
    int t;
    stack *tmp;
    stack *p;
    stack *new;

    if (stack_count(*a) > 1)
    {
        tmp = *a;
        while (tmp)
        {
            if (!tmp->next)
            {
                t = tmp->value;
                p->next = NULL;
                free(tmp);
                break ;
            }
            p = tmp;
            tmp = tmp->next;
        }
        push(a, t);
    }
}

void    rotate_rb(stack **a)
{
    int t;
    stack *tmp;
    stack *p;
    stack *new;

    if (stack_count(*a) > 1)
    {
        tmp = *a;
        while (tmp)
        {
            if (!tmp->next)
            {
                t = tmp->value;
                p->next = NULL;
                free(tmp);
                break ;
            }
            p = tmp;
            tmp = tmp->next;
        }
        push(a, t);
    }
}

void    rotate_rab(stack **a, stack **b)
{
    rotate_ra(a);
    rotate_rb(b);
}

void        rotate_ab(stack **a, stack **b)
{
    rotate_a(a);
    rotate_b(b);
}

void        print_stack(stack *s)
{
    stack *tmp;

    tmp  = s;
    printf("---------------\n");
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    printf("---------------\n");
}

int main()
{
    int p;
    
    stack *a, *b;
    a = NULL;
    b = NULL;

    push(&a,12);
    push(&a, 6);
    push(&a, 1);
    
    push(&b,10);
    push(&b, 8);
    push(&b, 2);

    print_stack(a);
    // print_stack(b);
    rotate_ra(&a);
    // sswap(&a, &b);
    print_stack(a);
    // print_stack(b);
    // while ((p = pop(&a)) != MIN_INT)
    // {
    //     printf("p = %d\n", p);
    // }
    // printf("\n\n\n");
    // while ((p = pop(&a)) != MIN_INT)
    // {
    //     printf("p = %d\n", p);
    // }
    
    return (0);
}