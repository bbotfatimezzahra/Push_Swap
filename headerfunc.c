/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:15:00 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/18 14:06:28 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_headernew(t_header **h)
{
	*h = malloc(sizeof(t_header));
	if (!(*h))
		return (0);
	(*h)->max = INT_MAX;
	(*h)->min = INT_MIN;
	(*h)->next = NULL;
	return (1);
}

void	set_header(t_header **h)
{
	t_list	*tmp;

	tmp = (*h)->next;
	if (!tmp)
		return ;
	(*h)->max = tmp->index;
	(*h)->min = tmp->index;
	while (tmp)
	{
		if (tmp->index > (*h)->max)
			(*h)->max = tmp->index;
		if (tmp->index < (*h)->min)
			(*h)->min = tmp->index;
		tmp = tmp->next;
	}
}
