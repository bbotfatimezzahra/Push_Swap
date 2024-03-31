/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:21:09 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/31 09:51:16 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_stack(t_list **stack)
{
	t_list	*pt;

	pt = (*stack);
	while (pt)
	{
		printf("%lu index : %d\n", pt->content, pt->index);
		pt = pt->next;
	}
}

int	main(int argc, char **argv)
{
	t_header	*h;

	if (argc == 1)
		return (0);
	h = NULL;
	if (!check_arg(argv) || !fill_stack(&h, argv, argc) || !check_dup(&h))
	{
		clean(&h);
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_sort(&h->next))
	{
		clean(&h);
		return (0);
	}
	if (ft_lstsize(h->next) <= 3)
	{
		sort_3stack(&h);
		clean(&h);
		return (0);
	}
	sort_stack(&h);
	clean(&h);
	return (0);
}
