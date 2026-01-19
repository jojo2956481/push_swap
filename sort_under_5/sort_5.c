/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:02:22 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 16:39:00 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(int *tab_a, int size_a)
{
	int	min;
	int	i;

	min = tab_a[0];
	i = 0;
	while (i < size_a)
	{
		if (min < tab_a[i])
			min = tab_a[i];
		i++;
	}
	return (min);
}

int	sort_5(t_stacks *stack, t_actions *actions, int silent)
{
	while (stack->size_a > 3)
	{
		if (stack->tab_a[0] == get_min(stack->tab_a, stack->size_a))
			pb(stack, actions, silent);
		else
			ra(stack->tab_a, stack->size_a, actions, silent);
	}
	sort_3(stack, actions, silent);
	if (stack->tab_b[0] < stack->tab_b[1])
		sa(stack->tab_a, stack->size_a, actions, silent);
	while (stack->size_b > 0)
		pa(stack, actions, silent);
	return (0);
}
