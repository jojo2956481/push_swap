/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:59:41 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 16:05:12 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "chunk_sort.h"

static int	calcul_index(int *tab_sort, t_stacks *stack, int chunk_size)
{
	int i;
	int j;

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
	//ft_printf("j = %d\n", j);
	return (j);
}


static int	push_max_from_b(t_stacks *stack,  t_actions *actions)
{
	int max;
	int index;

	max = find_max_value(stack->tab_b, *stack->size_b);
	index = find_index(stack->tab_b, *stack->size_b, max);

	if (index <= *stack->size_b / 2)
	{
		while (index-- > 0)
			rb(stack, actions);
	}
	else
	{
		index = *stack->size_b - index;
		while (index-- > 0)
			rrb(stack, actions);
	}
	pa(stack, actions);
	return (count);
}

int chunk_sort_opt(t_stacks *stack, t_actions *actions)
{
	int i;
	int chunk_size;
	int chunk_len;
	int **tab_sort;
	int k;
	int j;
	int y;

	chunk_size = isqrt(stack->size_a);
	chunk_len = stack->size_a / chunk_size;
	tab_sort = take_index(stack->tab_a, stack->size_a, chunk_size);
	j = 0;
	while (j < chunk_len)
	{
		i = 0;
		while (i < chunk_size)
		{
			k = calcul_index(tab_sort[j], stack, chunk_size);
			y = -1;
			if (k > (stack->size_a / 2))
			{
				k = stack->size_a - k;
				while (++y < k)
					rra(stack, actions);
			}
			else
			{
				while (++y < k)
					ra(stack, actions);
			}
			pb(stack, actions);
			i++;
		}
		j++;
	}
	while (stack->size_b > 0)
		push_max_from_b(stack, actions);
	return (0);
}

