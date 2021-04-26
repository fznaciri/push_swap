/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:44:17 by mac               #+#    #+#             */
/*   Updated: 2021/04/25 12:44:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int     check_sort(stack *a, stack *b)
{
    stack *tmp;
    
    if (b)
        return 0;
    tmp = a;
    while (tmp)
    {
        if (tmp->next && tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
        
}