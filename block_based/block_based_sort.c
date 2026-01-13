/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:11:09 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/11 08:11:11 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "block_based.h"

#include <unistd.h>

int find_min(int *cpy_tab, int nb_block, int *idx_min, int size_total)
{
	int i = 0;
	int best_block = -1;
	int min_val = 2147483647;

	while (i < nb_block)
	{
		int current_idx = idx_min[i];
		int block_limit = (i * 3) + 3;

		if (current_idx < block_limit && current_idx < size_total)
		{
			if (cpy_tab[current_idx] < min_val)
			{
				min_val = cpy_tab[current_idx];
				best_block = i;
			}
		}
		i++;
	}
	return (best_block);
}

int	init_utils(int **idx_min, int *size_a)
{
	int	i;
	int	nb_block;

	i = 0;
	nb_block = *size_a / 3;
	if (*size_a % 3 != 0)
		nb_block++;
	*idx_min = malloc(sizeof(int) * nb_block);
	if (!*idx_min)
		return (0);
	while (i < nb_block)
	{
		(*idx_min)[i] = i * 3;
		i++;
	}
	return (nb_block);
}

int find_pos(int *tab, int size, int value)
{
	int i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (0);
}

static void	move_to_top(t_stacks *stack, int target, int *counter, t_actions *actions)
{
	int	pos;

	pos = find_pos(stack->tab_a, stack->size_a, target);
	if (pos <= stack->size_a / 2)
	{
		while (stack->tab_a[0] != target)
		{
			ra(stack->tab_a, stack->size_a, actions);
			(*counter)++;
		}
	}
	else
	{
		while (stack->tab_a[0] != target)
		{
			rra(stack->tab_a, stack->size_a, actions);
			(*counter)++;
		}
	}
}

static void	empty_b(t_stacks *stack, int *counter, t_actions *actions)
{
	while (stack->size_b > 0)
	{
		pa(stack, actions);
		(*counter)++;
	}
}

int	block_sort(t_stacks *stack, t_actions *actions)
{
	int	*idx_min;
	int	*cpy_tab;
	int	nb_block;
	int	b_idx;
	int	c;
	int	total;

	c = 0;
	total = stack->size_a;
	cpy_tab = block_sort_without_rules(stack->tab_a, stack->size_a);
	nb_block = init_utils(&idx_min, &stack->size_a);
	while (stack->size_a > 0)
	{
		b_idx = find_min(cpy_tab, nb_block, idx_min, total);
		move_to_top(stack, cpy_tab[idx_min[b_idx]], &c, actions);
		pb(stack, actions);
		c++;
		idx_min[b_idx]++;
	}
	empty_b(stack, &c, actions);
	free(idx_min);
	free(cpy_tab);
	int i = 0;
	while (i < stack->size_a)
	{
		__builtin_printf("%d\n", stack->tab_a[i]);
		i++;
	}
	return (c);
}

/*
int main(void)
{
	int tab_a[] = {5,6,3,8,9};
	int tab_b[5];
	int size_a = 5;
	int size_b = 0;
	int i = 0;

	block_sort(tab_a, tab_b, &size_a, &size_b);
	while (i < size_a)
	{
		__builtin_printf("%d\n", tab_a[i]);
		i++;
	}
}*/