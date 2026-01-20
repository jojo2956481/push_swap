/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:28:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 15:39:05 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(int *tab, int size)
{
	int	i;
	int	min_idx;

	i = 0;
	min_idx = 0;
	while (++i < size)
	{
		if (tab[i] < tab[min_idx])
			min_idx = i;
	}
	return (min_idx);
}

void	sort_three(t_stacks *s, t_actions *act, int silent)
{
	int	a;
	int	b;
	int	c;

	a = s->tab_a[0];
	b = s->tab_a[1];
	c = s->tab_a[2];
	if (a > b && b < c && a < c)
		sa(s->tab_a, s->size_a, act, silent);
	else if (a > b && b > c)
	{
		sa(s->tab_a, s->size_a, act, silent);
		rra(s->tab_a, s->size_a, act, silent);
	}
	else if (a > b && b < c && a > c)
		ra(s->tab_a, s->size_a, act, silent);
	else if (a < b && b > c && a < c)
	{
		sa(s->tab_a, s->size_a, act, silent);
		ra(s->tab_a, s->size_a, act, silent);
	}
	else if (a < b && b > c && a > c)
		rra(s->tab_a, s->size_a, act, silent);
}

void	move_to_top(t_stacks *s, int target_idx, t_actions *act, int silent)
{
	if (target_idx <= s->size_a / 2)
	{
		while (target_idx > 0)
		{
			ra(s->tab_a, s->size_a, act, silent);
			target_idx--;
		}
	}
	else
	{
		while (target_idx < s->size_a)
		{
			rra(s->tab_a, s->size_a, act, silent);
			target_idx++;
		}
	}
}

int	selection_sort(t_stacks *stack, t_actions *actions, int silent)
{
	int	min_idx;

	if (stack->size_a <= 1)
		return (0);
	if (stack->size_a == 2 && stack->tab_a[0] > stack->tab_a[1])
	{
		sa(stack->tab_a, stack->size_a, actions, silent);
		return (0);
	}
	while (stack->size_a > 3)
	{
		min_idx = find_min_index(stack->tab_a, stack->size_a);
		move_to_top(stack, min_idx, actions, silent);
		pb(stack, actions, silent);
	}
	sort_three(stack, actions, silent);
	while (stack->size_b > 0)
		pa(stack, actions, silent);
	return (0);
}
