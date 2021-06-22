/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:00:12 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/22 19:30:56 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/stack.h"

int push(stack **s, int value, int chunk)
{
    stack *new;

    new = malloc(sizeof(stack));
    if (!new)
        return (0);
    new->value = value;
    new->chunk = chunk;
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
    free(tmp);
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
    int t1, t2, c1, c2;

    if (stack_count(*s) > 1)
    {
        c1 = (*s)->chunk;
        t1 = pop(s);
        c2 = (*s)->chunk;
        t2 = pop(s);
        push(s, t1, c1);
        push(s, t2, c2);
    }
}

void    sswap(stack **a, stack **b)
{
    swap(a);
    swap(b);
}

void    push_a(stack **a, stack **b, int chunk)
{
    int  t;
    
    if (stack_count(*b) >= 1)
    {
        t = pop(b);
        push(a, t, chunk);
    }
}

void    push_b(stack **a, stack **b, int chunk)
{
    int  t;
    
    if (*a)
    {
        t = pop(a);
        push(b, t, chunk);
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

int    peek_s(const stack *stack)
{
    if (!stack)
        return (MIN_INT);
    return (stack->value);
}

void    rotate_ra(stack **a)
{
    int t;
    int c;
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
                c = tmp->chunk;
                p->next = NULL;
                free(tmp);
                break ;
            }
            p = tmp;
            tmp = tmp->next;
        }
        push(a, t, c);
    }
}

void    rotate_rb(stack **a)
{
    int t;
    int c;
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
                c = tmp->chunk;
                p->next = NULL;
                free(tmp);
                break ;
            }
            p = tmp;
            tmp = tmp->next;
        }
        push(a, t, c);
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

void        print_stack(stack *a, stack *b)
{
    stack *tmp1;
    stack *tmp2;

    tmp1  = a;
    tmp2 = b;
    printf("---------------\n");
    while (tmp1 || tmp2)
    {
        if (tmp1 && tmp2)
            printf("%d\t\t\t%d\n", tmp1->value, tmp2->value);
        if (!tmp1 && tmp2)
            printf("%s\t\t\t%d\n", " ", tmp2->value);
        if (tmp1 && !tmp2)
            printf("%d\t\t\t%s\n", tmp1->value, " ");
        if (tmp1)
            tmp1 = tmp1->next;
        if (tmp2)
            tmp2 = tmp2->next;
    }
    printf("---------------\n");
}

void    clear_stack(stack **s)
{
    stack *tmp;

    if (*s)
    {
        while (*s)
        {
            tmp = *s;
            *s = tmp->next;
            free(tmp);
        }
    }
}

// int main()
// {
//     int p;
    
//     stack *a, *b;
//     a = NULL;
//     b = NULL;

//     push(&a,12);
//     push(&a, 6);
//     push(&a, 1);
    
//     push(&b,10);
//     push(&b, 8);
//     push(&b, 2);

//     print_stack(a);
//     // print_stack(b);
//     rotate_ra(&a);
//     // sswap(&a, &b);
//     print_stack(a);
//     // print_stack(b);
//     // while ((p = pop(&a)) != MIN_INT)
//     // {
//     //     printf("p = %d\n", p);
//     // }
//     // printf("\n\n\n");
//     // while ((p = pop(&a)) != MIN_INT)
//     // {
//     //     printf("p = %d\n", p);
//     // }
    
//     return (0);
// }