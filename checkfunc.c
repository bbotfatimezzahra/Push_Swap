/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:40:07 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/22 08:55:38 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_arg(char **list)
{
	int		i;
	int		j;
	char	*c;

	i = 1;
	while (list[i])
	{
		if (!worth_check(list[i]))
			return (0);
		c = list[i];
		j = 0;
		while (c[j])
		{
			if (!ft_isdigit(c[j]) && !ft_isspace(c[j]) && !ft_issign(c[j]))
				return (0);
			if (ft_issign(c[j]) && !ft_isdigit(c[j + 1]))
				return (0);
			if (ft_issign(c[j]) && !ft_isspace(c[j - 1]) && j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dup(t_header **h)
{
	t_list	*t;
	t_list	*m;
	int		dup;

	t = (*h)->next;
	while (t)
	{
		m = (*h)->next;
		dup = -1;
		while (m)
		{
			if (t->content == m->content)
				dup++;
			if (dup > 0)
				return (0);
			m = m->next;
		}
		t = t->next;
	}
	return (1);
}

int	check_sort(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
