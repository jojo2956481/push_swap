/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:43:36 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/14 08:43:42 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "block_based.h"

static int	find_min(int *cpy_tab, int nb_block, int *idx_min, int size_total)
{
	int	i;
	int	best_block;
	int	min_val;
	int	current_idx;
	int	block_limit;

	i = 0;
	best_block = -1;
	min_val = 2147483647;
	while (i < nb_block)
	{
		current_idx = idx_min[i];
		block_limit = (i * 3) + 3;
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

static int	init_utils(int **idx_min, int *size_a)
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

static void	move_to_top(t_stacks *stack, int target, t_actions *act)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < stack->size_a)
	{
		if (stack->tab_a[i] == target)
		{
			pos = i;
			break ;
		}
	}
	if (pos <= stack->size_a / 2)
		while (stack->tab_a[0] != target)
			ra(stack->tab_a, stack->size_a, act);
	else
		while (stack->tab_a[0] != target)
			rra(stack->tab_a, stack->size_a, act);
}

int	block_sort(t_stacks *stack, t_actions *actions)
{
	int	*idx_min;
	int	*cpy_tab;
	int	nb_block;
	int	b_idx;
	int	total;

	total = stack->size_a;
	cpy_tab = block_sort_without_rules(stack->tab_a, stack->size_a);
	nb_block = init_utils(&idx_min, &stack->size_a);
	if (nb_block == 0)
		return (free_all(cpy_tab, idx_min, 1, 1));
	while (stack->size_a > 0)
	{
		b_idx = find_min(cpy_tab, nb_block, idx_min, total);
		move_to_top(stack, cpy_tab[idx_min[b_idx]], actions);
		pb(stack, actions);
		idx_min[b_idx]++;
	}
	while (stack->size_b > 0)
		pa(stack, actions);
	free(idx_min);
	free(cpy_tab);
	return (0);
}

/*
	int i = 0;
	while (i < stack->size_a)
	{
		__builtin_printf("%d\n", stack->tab_a[i]);
		i++;
	}
*/