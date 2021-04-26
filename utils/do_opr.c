/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_opr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:15:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/26 16:19:34 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void    do_opr(stack **a, stack **b, char *opr)
{
    if (!ft_strcmp(opr, "sa"))
        swap(a);
    if (!ft_strcmp(opr, "sb"))
        swap(b);
    if (!ft_strcmp(opr, "ss"))
        sswap(a, b);
    if (!ft_strcmp(opr, "pa"))
        push_a(a, b);
    if (!ft_strcmp(opr, "pb"))
        push_b(a, b);
    if (!ft_strcmp(opr, "ra"))
        rotate_a(a);
    if (!ft_strcmp(opr, "rb"))
        rotate_b(b);
    if (!ft_strcmp(opr, "rr"))
        rotate_ab(a, b);
    if (!ft_strcmp(opr, "rra"))
        rotate_ra(a);
    if (!ft_strcmp(opr, "rrb"))
        rotate_rb(b);
    if (!ft_strcmp(opr, "rrr"))
        rotate_rab(a, b);
}