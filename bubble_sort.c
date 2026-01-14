/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:16:58 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 15:37:56 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sort(t_stacks *stack, t_actions *actions)
{
	int	i;
	int	j;

	j = 0;
	while (j < stack->size_a - 1)
	{
		i = 0;
		while (i < stack->size_a - 1 - j)
		{
			if (stack->tab_a[0] > stack->tab_a[1])
				sa(stack->tab_a, stack->size_a, actions);
			ra(stack->tab_a, stack->size_a, actions);
			i++;
		}
		i = 0;
		while (i < stack->size_a - 1 - j)
		{
			rra(stack->tab_a, stack->size_a, actions);
			i++;
		}
		j++;
	}
	return (0);
}
