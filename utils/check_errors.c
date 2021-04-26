/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:04:27 by mac               #+#    #+#             */
/*   Updated: 2021/04/26 17:07:26 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void check_errors(char **av, int ac)
{
    int i;

    i = 0;
    while (av[ac][i])
    {
        if (!(av[ac][0] == '+' || av[ac][0] == '-' || ft_isdigit(av[ac][i])))
            ft_puterror();
        i++;
    }
    if (is_dup(av, ac) || ft_atoi(av[ac]) >  MAX_INT || ft_atoi(av[ac]) <  MIN_INT)
        ft_puterror();
}