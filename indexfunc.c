/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbbot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:12:48 by fbbot             #+#    #+#             */
/*   Updated: 2024/03/31 09:50:30 by fbbot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	median_of_three(int x, int y, int z)
{
	if ((x < y && y < z) || (z < y && y < x))
		return (y);
	else if ((y < x && x < z) || (z < x && x < y))
		return (x);
	else
		return (z);
}

void	switch_elements(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(long *arr, int low, int high)
{
	long	pivot;
	int		i;
	int		j;

	if (low < high)
	{
		pivot = arr[median_of_three(low, (low + high) / 2, high)];
		i = low;
		j = high;
		while (i <= j)
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;
			if (i <= j)
				switch_elements(&arr[i++], &arr[j--]);
		}
		if (low < j)
			quick_sort(arr, low, j);
		if (i < high)
			quick_sort(arr, i, high);
	}
}

void	index_stack(t_list **a, long *arr, int size)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < size && arr[i] != tmp->content)
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	sort_array(t_header **h)
{
	int		size;
	int		i;
	long	*arr;
	t_list	*a;

	a = (*h)->next;
	size = ft_lstsize(a);
	arr = malloc((size + 1) * sizeof(long));
	if (!arr)
		return ;
	i = 0;
	while (i < size)
	{
		arr[i++] = a->content;
		a = a->next;
	}
	quick_sort(arr, 0, size - 1);
	index_stack(&(*h)->next, arr, size);
	free(arr);
}
