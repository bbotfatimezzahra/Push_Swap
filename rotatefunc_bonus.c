/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatefunc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:58:13 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/19 16:13:57 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rab_bonus(t_header **h)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize((*h)->next) <= 1)
		return ;
	first = (*h)->next;
	last = ft_lstlast(first);
	last->next = first;
	(*h)->next = first->next;
	first->next = NULL;
	set_header(h);
}

void	rr_bonus(t_header **a, t_header **b)
{
	rab(a, 0);
	rab(b, 0);
	set_header(a);
	set_header(b);
}

void	rrab_bonus(t_header **h)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize((*h)->next) <= 1)
		return ;
	last = ft_lstlast((*h)->next);
	tmp = (*h)->next;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = (*h)->next;
	(*h)->next = last;
	set_header(h);
}

void	rrr_bonus(t_header **a, t_header **b)
{
	rrab(a, 0);
	rrab(b, 0);
	set_header(a);
	set_header(b);
}
