/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkutil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:54:43 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/22 08:55:26 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_issign(int c)
{
	if (c != '-' && c != '+')
		return (0);
	return (1);
}

int	ft_isspace(int c)
{
	if (c != 32 && (c < 9 || c > 13))
		return (0);
	return (1);
}

int	worth_check(char *arg)
{
	char	c;

	c = '0';
	while (c <= '9')
		if (ft_strchr(arg, c++))
			return (1);
	return (0);
}
