/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:13:11 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 17:01:23 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int	sort_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	copy_tab(int *tab_a, int *tab_sort, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab_sort[i] = tab_a[i];
		i++;
	}
	return (0);
}

int	indexation(int *tab_sort, int *tab, int *tab_index, int size)
{
	int	i;
	int	y;

	y = 0;
	while (y < size)
	{
		i = 0;
		while (tab[y] != tab_sort[i])
			i++;
		tab_index[y] = i;
		y++;
	}
	return (0);
}

int	is_sorted(int *tab_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	radix(int *tab, int size)
{
	int	i;
	int	count; //useless
	int	*tab_a; //useless
	int	*tab_b; //useless
	int	size_a; //useless
	int	size_b; //useless
	int	*tab_sort;
	int	*tab_index;
	int	bit;
	int	k;
	int	max_bit;
	int	max_index;

	tab_a = tab; //useless
	tab_b = ft_calloc(size, sizeof(int));//useless
	size_a = size; // faire l'inverse
	size_b = 0; //useless
	count = 0;//useless
	bit = 1;
	tab_sort = ft_calloc(size, sizeof(int));
	if (tab_sort == NULL)
		return (free_all(NULL, NULL, 1, 1));
	tab_index = ft_calloc(size, sizeof(int));
	if (tab_index == NULL)
		return (free_all(tab_sort, NULL, 1, 1));
	copy_tab(tab, tab_sort, size);
	sort_tab(tab_sort, size);
	indexation(tab_sort, tab, tab_index, size);
	max_bit = 0;
	max_index = tab_sort[size - 1];
	while ((max_index >> max_bit) != 0)
		max_bit++;
	max_bit = (max_bit + 0);
	bit = 0;
	while (bit < max_bit)
	{
		i = 0;
		while (i < size)
		{
			if (((tab_index[i] >> bit) & 1) == 0)
				count += pb(tab_a, tab_b, &size_a, &size_b);
			else
				count += ra(tab_a, size_a);
			i++;
		}
		while (size_b > 0)
			count += pa(tab_a, tab_b, &size_a, &size_b);
		if (is_sorted(tab_a, size_a) == 1)
			break ;
		bit++;
		indexation(tab_sort, tab, tab_index, size);
	}
	return (count); // on doit return 0 si OK, et -1 si pb
}
