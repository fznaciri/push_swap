/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_chunkempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:43:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:12:52 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_chunkempty(t_stack *a, int chunk)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->chunk == chunk)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
