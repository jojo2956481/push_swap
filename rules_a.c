/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:17:20 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 10:09:25 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// Swap the first two elements at the top of stack a
int	sa(int *a, int size_a, t_actions *actions, int silent)
{
	int			temp;

	actions->sa += 1;
	if (silent == 0)
		ft_printf(1, "sa\n");
	actions->nb_op += 1;
	if (size_a <= 1)
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (1);
}

// Take the first element at the top of b and put it at the top of a.
int	pa(t_stacks *stack, t_actions *actions, int silent)
{
	int	i;

	if (stack->size_b <= 0)
		return (0);
	i = stack->size_a;
	while (i > 0)
	{
		stack->tab_a[i] = stack->tab_a[i - 1];
		i--;
	}
	stack->tab_a[0] = stack->tab_b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->tab_b[i] = stack->tab_b[i + 1];
		i++;
	}
	stack->size_b--;
	stack->size_a++;
	actions->pa += 1;
	if (silent == 0)
		ft_printf(1, "pa\n");
	actions->nb_op += 1;
	return (1);
}

// Shift up all elements of stack a by one
int	ra(int *a, int size_a, t_actions *actions, int silent)
{
	int			temp;
	int			i;

	actions->ra += 1;
	if (silent == 0)
		ft_printf(1, "ra\n");
	actions->nb_op += 1;
	if (size_a < 2)
		return (0);
	temp = a[0];
	i = 0;
	while (i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size_a - 1] = temp;
	return (1);
}

// Shift down all elements of stack a by one.
int	rra(int *a, int size_a, t_actions *actions, int silent)
{
	int			temp;
	int			i;

	actions->rra += 1;
	if (silent == 0)
		ft_printf(1, "rra\n");
	actions->nb_op += 1;
	if (size_a < 2)
		return (0);
	temp = a[size_a - 1];
	i = size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	return (1);
}
