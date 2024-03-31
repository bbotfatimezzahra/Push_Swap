/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:47:01 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/31 09:41:38 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "./getnextline/get_next_line.h"

typedef struct s_list
{
	long			content;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct s_header
{
	int		max;
	int		min;
	t_list	*next;
}				t_header;

typedef struct s_move
{
	int		nbr;
	char	dir;
}				t_move;

typedef struct s_action
{
	t_move	comb;
	t_move	sa;
	t_move	sb;
	int		total;
}				t_action;

int		ft_isdigit(int c);
int		ft_issign(int c);
int		ft_isspace(int c);
int		worth_check(char *str);
int		check_arg(char **argv);
int		fill_stack(t_header **h, char **argv, int argc);
int		check_dup(t_header **h);
int		ft_headernew(t_header **h);
t_list	*ft_lstnew(long content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	set_header(t_header **a);
int		check_sort(t_list **a);
void	sort_3stack(t_header **h);
void	sort_array(t_header **h);
void	sort_stack(t_header **h);
int		min(int a, int b);
int		choose_target(t_header *c, int a, int type);
t_move	count_move(t_list *tmp, int c);
void	make_move(t_move move, t_header **h, int i);
void	choose_action(t_header **h, t_header **c);
void	sab(t_header **l, int i);
void	ss(t_header **a, t_header **b);
void	pab(t_header **s1, t_header **s2, int i);
void	rab(t_header **l, int i);
void	rr(t_header **a, t_header **b);
void	rrab(t_header**l, int i);
void	rrr(t_header **a, t_header **b);
void	sab_bonus(t_header **l);
void	ss_bonus(t_header **a, t_header **b);
void	pab_bonus(t_header **s1, t_header **s2);
void	rab_bonus(t_header **l);
void	rr_bonus(t_header **a, t_header **b);
void	rrab_bonus(t_header**l);
void	rrr_bonus(t_header **a, t_header **b);
void	clean(t_header **h);
void	print_stack(t_list **a);

#endif
