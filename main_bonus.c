/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:57:49 by fbbot             #+#    #+#             */
/*   Updated: 2024/04/04 17:52:37 by fbbot            ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	apply_inst(t_header **h, t_header **c, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sab_bonus(h);
	else if (!ft_strcmp(str, "sb\n"))
		sab_bonus(c);
	else if (!ft_strcmp(str, "ss\n"))
		ss_bonus(h, c);
	else if (!ft_strcmp(str, "pa\n"))
		pab_bonus(c, h);
	else if (!ft_strcmp(str, "pb\n"))
		pab_bonus(h, c);
	else if (!ft_strcmp(str, "ra\n"))
		rab_bonus(h);
	else if (!ft_strcmp(str, "rb\n"))
		rab_bonus(c);
	else if (!ft_strcmp(str, "rr\n"))
		rr_bonus(h, c);
	else if (!ft_strcmp(str, "rra\n"))
		rrab_bonus(h);
	else if (!ft_strcmp(str, "rrb\n"))
		rrab_bonus(c);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr_bonus(h, c);
	else
		return (0);
	return (1);
}

void	sort_by_inst(t_header **h, t_header **c)
{
	char		*str;

	str = get_next_line(0);
	while (str)
	{
		if (!apply_inst(h, c, str))
		{
			free(str);
			clean(h);
			clean(c);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_header	*h;
	t_header	*c;

	if (argc == 1)
		return (0);
	h = NULL;
	c = NULL;
	if (!check_arg(argv) || !fill_stack(&h, argv, argc) || !check_dup(&h))
	{
		clean(&h);
		write(2, "Error\n", 6);
		return (0);
	}
	ft_headernew(&c);
	sort_by_inst(&h, &c);
	if (h->next && check_sort(&h->next) && !c->next)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clean(&h);
	clean(&c);
	return (0);
}
