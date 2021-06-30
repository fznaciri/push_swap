/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:00:12 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/24 19:25:06 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

int	push(t_stack **s, int value, int chunk)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->chunk = chunk;
	new->next = *s;
	*s = new;
	return (1);
}

int	pop(t_stack **s)
{
	int		result;
	t_stack	*tmp;

	if (*s == NULL)
		return (MIN_INT);
	tmp = *s;
	result = tmp->value;
	*s = tmp->next;
	free(tmp);
	return (result);
}

int	stack_count(t_stack *a)
{
	t_stack	*tmp;
	int		c;

	tmp = a;
	c = 0;
	while (tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

int	peek_s(const t_stack *t_stack)
{
	if (!t_stack)
		return (MIN_INT);
	return (t_stack->value);
}

void	clear_stack(t_stack **s)
{
	t_stack	*tmp;

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
