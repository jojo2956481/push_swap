/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:28:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 15:39:05 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insertion_sort(t_stacks *stack, t_actions *actions)
{
	int	i;
	int	index;

	index = 1;
	while (index < stack->size_a)
	{
		i = 0;
		while (i < index)
		{
			ra (stack->tab_a, stack->size_a, actions);
			i++;
		}
		while (i > 0 && stack->tab_a[0] > stack->tab_a[1])
		{
			sa(stack->tab_a, stack->size_a, actions);
			rra(stack->tab_a, stack->size_a, actions);
			i--;
		}
		while (i > 0)
		{
			rra(stack->tab_a, stack->size_a, actions);
			i--;
		}
		index++;
	}
	ra(stack->tab_a, stack->size_a, actions);
	return (0);
}



