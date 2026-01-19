/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:54:36 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 16:38:36 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_stacks *stack, t_actions *actions, int silent)
{
	int	x;
	int	y;
	int	z;

	x = stack->tab_a[0];
	y = stack->tab_a[1];
	z = stack->tab_a[2];
	if (x > y && y < z && x < z)
		sa(stack->tab_a, stack->size_a, actions, silent);
	else if (x > y && y > z)
	{
		sa(stack->tab_a, stack->size_a, actions, silent);
		rra(stack->tab_a, stack->size_a, actions, silent);
	}
	else if (x > y && y < z && x > z)
		ra(stack->tab_a, stack->size_a, actions, silent);
	else if (x < y && y > z && x < z)
	{
		sa(stack->tab_a, stack->size_a, actions, silent);
		ra(stack->tab_a, stack->size_a, actions, silent);
	}
	else if (x < y && y > z && x > z)
		rra(stack->tab_a, stack->size_a, actions, silent);
	return (0);
}
