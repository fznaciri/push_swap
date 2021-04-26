/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:04:27 by mac               #+#    #+#             */
/*   Updated: 2021/04/25 13:05:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void check_errors(char **av, int ac)
{
    int i;

    i = 0;
    while (av[ac][i])
    {
            //av[ac][0] != '+' || av[ac][0] != '-' || 
        if (!ft_isdigit(av[ac][i]))
            ft_puterror();
        i++;
    }
    if (is_dup(av, ac) || ft_atoi(av[ac]) >  MAX_INT || ft_atoi(av[ac]) <  MIN_INT)
        ft_puterror();
}