/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 11:05:06 by mac               #+#    #+#             */
/*   Updated: 2021/06/24 11:39:24 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_opr	*ft_opnew(char *content)
{
	t_opr	*new;

	new = malloc(sizeof(t_opr));
	if (!new)
		return (NULL);
	new->op = content;
	new->next = NULL;
	return (new);
}
