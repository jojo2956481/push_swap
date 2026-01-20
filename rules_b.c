/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:17:20 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:45:54 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// Swap the first two elements at the top of stack b
int	sb(int *b, int size_b, t_actions *actions, int silent)
{
	int			temp;

	actions->sb += 1;
	if (silent == 0)
		ft_printf(1, "sb\n");
	actions->nb_op += 1;
	if (size_b <= 1)
		return (0);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	return (1);
}

// Take the first element at the top of a and put it at the top of b.
int	pb(t_stacks *stack, t_actions *actions, int silent)
{
	int	i;

	if (stack->size_a <= 0)
		return (0);
	i = stack->size_b;
	while (i > 0)
	{
		stack->tab_b[i] = stack->tab_b[i - 1];
		i--;
	}
	stack->tab_b[0] = stack->tab_a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->tab_a[i] = stack->tab_a[i + 1];
		i++;
	}
	stack->size_a--;
	stack->size_b++;
	actions->pb += 1;
	if (silent == 0)
		ft_printf(1, "pb\n");
	actions->nb_op += 1;
	return (1);
}

// Shift up all elements of stack b by one.
int	rb(int *b, int size_b, t_actions *actions, int silent)
{
	int			temp;
	int			i;

	actions->rb += 1;
	if (silent == 0)
		ft_printf(1, "rb\n");
	actions->nb_op += 1;
	if (size_b < 2)
		return (0);
	temp = b[0];
	i = 0;
	while (i < size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size_b - 1] = temp;
	return (1);
}

// Shift down all elements of stack b by one.
int	rrb(int *b, int size_b, t_actions *actions, int silent)
{
	int			temp;
	int			i;

	actions->nb_op += 1;
	if (silent == 0)
		ft_printf(1, "rrb\n");
	actions->rrb += 1;
	if (size_b < 2)
		return (0);
	temp = b[size_b - 1];
	i = size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	return (1);
}
