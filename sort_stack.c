/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:57:35 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/31 09:51:20 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	count_max(t_list *a, long *max, long *min)
{
	t_list	*tmp;

	tmp = a;
	*min = tmp->content;
	*max = tmp->content;
	while (tmp)
	{
		if (*min > tmp->content)
			*min = tmp->content;
		if (*max < tmp->content)
			*max = tmp->content;
		tmp = tmp->next;
	}
}

void	sort_3stack(t_header **h)
{
	t_list	*tmp;
	long	min;
	long	max;

	if (check_sort(&(*h)->next))
		return ;
	set_header(h);
	tmp = (*h)->next;
	count_max(tmp, &max, &min);
	if (tmp->content == min)
	{
		sab(h, 1);
		rab(h, 1);
	}
	else if (ft_lstlast(tmp)->content == max || ft_lstsize(tmp) == 2)
		sab(h, 1);
	else if (tmp->next->content == max)
		rrab(h, 1);
	else if (tmp->content == max && tmp->next->content == min)
		rab(h, 1);
	else
	{
		rab(h, 1);
		sab(h, 1);
	}
}

void	sort_stack(t_header **h)
{
	t_header	*c;
	t_move		move;
	int			target;

	if (ft_lstsize((*h)->next) < 3)
		return ;
	sort_array(h);
	set_header(h);
	ft_headernew(&c);
	while (ft_lstsize((*c).next) < 2)
		pab(h, &c, 1);
	while (ft_lstsize((*h)->next) > 3 && !check_sort(&(*h)->next))
		choose_action(h, &c);
	sort_3stack(h);
	while (ft_lstsize((*c).next))
	{
		target = choose_target(*h, (*c).next->index, 2);
		move = count_move((*h)->next, target);
		make_move(move, h, 1);
		pab(&c, h, 2);
	}
	make_move(count_move((*h)->next, (*h)->min), h, 1);
	clean(&c);
}
