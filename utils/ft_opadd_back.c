/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:19:11 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/18 10:51:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	ft_opadd_back(t_op **alst, t_op *new)
{
	t_op *tmp;

	tmp = *alst;
	if (tmp)
	{
		tmp = ft_oplast(tmp);
		tmp->next = new;
	}
	else
		*alst = new;
}
