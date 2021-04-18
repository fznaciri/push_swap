/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:19:11 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/04/18 14:08:02 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ft_opadd_back(t_opr **alst, t_opr *new)
{
	t_opr *tmp;

	tmp = *alst;
	if (tmp)
	{
		tmp = ft_oplast(tmp);
		tmp->next = new;
	}
	else
		*alst = new;
}
