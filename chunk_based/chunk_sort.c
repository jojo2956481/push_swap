/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:59:41 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 12:19:23 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "chunk_sort.h"

static int	calcul_index(int *tab_sort, t_stacks *stack, int chunk_size)
{
	int	i;
	int	j;

	j = 0;
	while (j < stack->size_a)
	{
		i = 0;
		while (i < chunk_size)
		{
			if (tab_sort[i] == stack->tab_a[j])
				return (j);
			i++;
		}
		j++;
	}
	return (j);
}

static int	push_max_from_b(t_stacks *stack, t_actions *actions, int silent)
{
	int	max;
	int	index;

	max = find_max_value(stack->tab_b, stack->size_b);
	index = find_index(stack->tab_b, stack->size_b, max);
	if (index <= stack->size_b / 2)
	{
		while (index-- > 0)
			rb(stack->tab_b, stack->size_b, actions, silent);
	}
	else
	{
		index = stack->size_b - index;
		while (index-- > 0)
			rrb(stack->tab_b, stack->size_b, actions, silent);
	}
	pa(stack, actions, silent);
	return (0);
}

static void	push_chunk_from_a(t_stacks *stack,
			t_actions *actions, int k, int silent)
{
	int	y;

	y = -1;
	if (k > (stack->size_a / 2))
	{
		k = stack->size_a - k;
		while (++y < k)
			rra(stack->tab_a, stack->size_a, actions, silent);
	}
	else
		while (++y < k)
			ra(stack->tab_a, stack->size_a, actions, silent);
	pb(stack, actions, silent);
}

int	chunk_sort(t_stacks *stack, t_actions *actions, int silent)
{
	int	i;
	int	chunk_size;
	int	chunk_len;
	int	**tab_sort;
	int	j;

	chunk_size = isqrt(stack->size_a);
	chunk_len = stack->size_a / chunk_size;
	tab_sort = take_index(stack->tab_a, stack->size_a, chunk_size, chunk_len);
	if (!tab_sort)
		return (1);
	j = 0;
	while (j < chunk_len)
	{
		i = -1;
		while (++i < chunk_size)
			push_chunk_from_a(stack, actions,
				calcul_index(tab_sort[j], stack, chunk_size), silent);
		j++;
	}
	while (stack->size_b > 0)
		push_max_from_b(stack, actions, silent);
	free_take_index(NULL, NULL, tab_sort);
	return (0);
}
