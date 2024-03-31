/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatefunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 07:47:10 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/19 13:52:49 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rab(t_header **h, int i)
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
	if (i == 1)
		write(1, "ra\n", 3);
	if (i == 2)
		write(1, "rb\n", 3);
	set_header(h);
}

void	rr(t_header **a, t_header **b)
{
	rab(a, 0);
	rab(b, 0);
	write(1, "rr\n", 3);
	set_header(a);
	set_header(b);
}

void	rrab(t_header **h, int i)
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
	if (i == 1)
		write(1, "rra\n", 4);
	if (i == 2)
		write(1, "rrb\n", 4);
	set_header(h);
}

void	rrr(t_header **a, t_header **b)
{
	rrab(a, 0);
	rrab(b, 0);
	write(1, "rrr\n", 4);
	set_header(a);
	set_header(b);
}
