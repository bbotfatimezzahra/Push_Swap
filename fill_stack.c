/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 07:09:20 by fbbot             #+#    #+#             */
/*   Updated: 2024/04/04 22:31:37 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_atoi(const char *str, int *index)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = *index;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (2147483649);
	}
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	*index = i;
	return (result * sign);
}

int	fill_stack(t_header **h, char **argv, int argc)
{
	t_list	*tmp;
	long	nbr;
	int		i;
	int		j;

	i = 1;
	if (!ft_headernew(h))
		return (0);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			nbr = ft_atoi(argv[i], &j);
			if (nbr > INT_MAX || nbr < INT_MIN)
				return (0);
			tmp = ft_lstnew(nbr);
			if (!tmp)
				return (0);
			ft_lstadd_back(&(*h)->next, tmp);
		}
		i++;
	}
	set_header(h);
	return (1);
}
