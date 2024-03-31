/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfunc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:55:27 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/19 16:13:18 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sab_bonus(t_header **h)
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
	set_header(h);
}

void	ss_bonus(t_header **a, t_header **b)
{
	sab(a, 0);
	sab(b, 0);
	set_header(a);
	set_header(b);
}

void	pab_bonus(t_header **a, t_header **b)
{
	t_list	*tmp;

	if (!ft_lstsize((*a)->next))
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	set_header(a);
	set_header(b);
}
