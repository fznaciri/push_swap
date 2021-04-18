/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:21 by mac               #+#    #+#             */
/*   Updated: 2021/04/18 10:53:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "stack.h"

typedef struct s_op
{
    char *op;
    struct s_op *next;
} t_op;

typedef struct s_checker
{
    stack *a;
    stack *b;
    char *line;
    t_op *op;
} t_checker;



#endif