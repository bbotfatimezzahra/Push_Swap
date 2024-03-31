/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 07:14:28 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/19 13:54:00 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sab(t_header **h, int i)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize((*h)->next) <= 1)
		return ;
	first = (*h)->next;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*h)->next = second;
	if (i == 1)
		write(1, "sa\n", 3);
	if (i == 2)
		write(1, "sb\n", 3);
	set_header(h);
}

void	ss(t_header **a, t_header **b)
{
	sab(a, 0);
	sab(b, 0);
	write(1, "ss\n", 3);
	set_header(a);
	set_header(b);
}

void	pab(t_header **a, t_header **b, int i)
{
	t_list	*tmp;

	if (!ft_lstsize((*a)->next))
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (i == 1)
		write(1, "pb\n", 3);
	if (i == 2)
		write(1, "pa\n", 3);
	set_header(a);
	set_header(b);
}
