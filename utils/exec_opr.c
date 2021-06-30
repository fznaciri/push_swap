/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_opr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:43:55 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/30 15:41:04 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exec_opr(t_stack **a, t_stack **b, int chunk, char *opr)
{
	ft_putendl_fd(opr, 1);
	do_opr(a, b, chunk, opr);
}
