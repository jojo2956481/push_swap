/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:13:11 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/15 12:03:01 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	copy_tab(int *tab_a, int *tab_sort, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab_sort[i] = tab_a[i];
		i++;
	}
}

void	indexation(int *tab_sort, int *tab, int *tab_index, int size)
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

int	radix(t_stacks *stack, t_actions *actions)
{
	int	i;
	int	*tab_sort;
	int	*tab_index;
	int	bit;
	int size;
	int	max_bit;
	int	max_index;

	size = stack->size_a;
	bit = 1;
	tab_sort = ft_calloc(size, sizeof(int));
	if (tab_sort == NULL)
		return (free_all(NULL, NULL, 1, 1));
	tab_index = ft_calloc(size, sizeof(int));
	if (tab_index == NULL)
		return (free_all(tab_sort, NULL, 1, 1));
	copy_tab(stack->tab_a, tab_sort, size);
	sort_tab(tab_sort, size);
	indexation(tab_sort, stack->tab_a, tab_index, size);
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
				pb(stack, actions);
			else
				ra(stack->tab_a, stack->size_a, actions);
			i++;
		}
		while (stack->size_b > 0)
			pa(stack, actions);
		if (is_sorted(stack->tab_a, stack->size_a) == 1)
			break ;
		bit++;
		indexation(tab_sort, stack->tab_a, tab_index, size);
	}
	return (0); // on doit return 0 si OK, et 1 si pb
}
