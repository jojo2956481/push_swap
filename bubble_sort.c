/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:16:58 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 12:29:30 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubble_sort(t_stacks *stack, t_actions *actions, int size)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			if (stack->tab_a[0] > stack->tab_a[1])
				count += sa(stack->tab_a, size, actions);
			count += ra(stack->tab_a, size, actions);
			i++;
		}
		i = 0;
		while (i < size - 1 - j)
		{
			count += rra(stack->tab_a, size, actions);
			i++;
		}
		j++;
	}
	return (count);
}
