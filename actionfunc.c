/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:10:58 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/18 11:11:51 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_action	count_action(t_header *h, t_header *c, int a)
{
	t_action	action;
	t_move		sa;
	t_move		sb;

	sa = count_move(h->next, a);
	sb = count_move(c->next, choose_target(c, a, 1));
	if (sa.dir == sb.dir)
	{
		action.comb.nbr = min(sa.nbr, sb.nbr);
		action.comb.dir = sa.dir;
		action.sa.nbr = sa.nbr - action.comb.nbr;
		action.sb.nbr = sb.nbr - action.comb.nbr;
		action.total = action.sa.nbr + action.sb.nbr + action.comb.nbr + 1;
	}
	else
	{
		action.comb.nbr = 0;
		action.sa.nbr = sa.nbr;
		action.sb.nbr = sb.nbr;
		action.total = action.sa.nbr + action.sb.nbr + 1;
	}
	action.sa.dir = sa.dir;
	action.sb.dir = sb.dir;
	return (action);
}

void	make_action(t_move move, t_header **h, t_header **c)
{
	while (move.nbr && move.dir == 't')
	{
		rr(h, c);
		move.nbr--;
	}
	while (move.nbr && move.dir == 'b')
	{
		rrr(h, c);
		move.nbr--;
	}
}

void	choose_action(t_header **h, t_header **c)
{
	t_list		*a;
	t_action	best;

	a = (*h)->next;
	best = count_action(*h, *c, (*a).index);
	while (a)
	{
		if (best.total > count_action(*h, *c, (*a).index).total)
			best = count_action(*h, *c, (*a).index);
		a = a->next;
	}
	make_action(best.comb, h, c);
	make_move(best.sa, h, 1);
	make_move(best.sb, c, 2);
	pab(h, c, 1);
}
