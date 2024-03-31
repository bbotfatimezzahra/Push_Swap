/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:08:55 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/19 14:30:52 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	choose_target(t_header *c, int a, int type)
{
	t_list	*b;
	int		target;

	if ((a >= c->max || a <= c->min) && type == 1)
		return (c->max);
	if ((a >= c->max || a <= c->min) && type == 2)
		return (c->min);
	b = c->next;
	if (type == 1)
		target = c->min;
	if (type == 2)
		target = c->max;
	while (b)
	{
		if (type == 1 && (a - b->index) >= 0 && a - target > a - b->index)
			target = b->index;
		if (type == 2 && (a - b->index) <= 0 && a - target < a - b->index)
			target = b->index;
		b = b->next;
	}
	return (target);
}

t_move	count_move(t_list *tmp, int c)
{
	t_move	best;
	int		top;
	int		bot;

	top = 0;
	bot = 0;
	while (tmp->index != c)
	{
		tmp = tmp->next;
		top++;
	}
	while (tmp)
	{
		tmp = tmp->next;
		bot++;
	}
	best.nbr = min(top, bot);
	if (top < bot)
		best.dir = 't';
	else
		best.dir = 'b';
	return (best);
}

void	make_move(t_move move, t_header **h, int i)
{
	while (move.nbr && move.dir == 't')
	{
		rab(h, i);
		move.nbr--;
	}
	while (move.nbr && move.dir == 'b')
	{
		rrab(h, i);
		move.nbr--;
	}
}
