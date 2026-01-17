/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:17:20 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/09 16:41:40 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// sa and sb at the same time.
int	ss(t_stacks *stack, t_actions *actions)
{
	int	tmp;

	if (stack->size_a < 2 || stack->size_b < 2)
		return (0);
	tmp = stack->tab_a[0];
	stack->tab_a[0] = stack->tab_a[1];
	stack->tab_a[1] = tmp;
	tmp = stack->tab_b[0];
	stack->tab_b[0] = stack->tab_b[1];
	stack->tab_b[1] = tmp;
	actions->ss += 1;
	ft_printf("ss\n");
	actions->nb_op += 1;
	return (1);
}

// ra and rb at the same time.
int	rr(t_stacks *stack, t_actions *actions)
{
	int	tmp;
	int	i;

	if (stack->size_a < 2 || stack->size_b < 2)
		return (0);
	tmp = stack->tab_a[0];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->tab_a[i] = stack->tab_a[i + 1];
	stack->tab_a[stack->size_a - 1] = tmp;
	tmp = stack->tab_b[0];
	i = -1;
	while (++i < stack->size_b - 1)
		stack->tab_b[i] = stack->tab_b[i + 1];
	stack->tab_b[stack->size_b - 1] = tmp;
	actions->rr += 1;
	ft_printf("rr\n");
	actions->nb_op += 1;
	return (1);
}

// rra and rrb at the same time.
int	rrr(t_stacks *stack, t_actions *actions)
{
	int	tmp;
	int	i;

	if (stack->size_a < 2 || stack->size_b < 2)
		return (0);
	tmp = stack->tab_a[stack->size_a - 1];
	i = stack->size_a;
	while (--i > 0)
		stack->tab_a[i] = stack->tab_a[i - 1];
	stack->tab_a[0] = tmp;
	tmp = stack->tab_b[stack->size_b - 1];
	i = stack->size_b;
	while (--i > 0)
		stack->tab_b[i] = stack->tab_b[i - 1];
	stack->tab_b[0] = tmp;
	actions->rrr += 1;
	ft_printf("rrr\n");
	actions->nb_op += 1;
	return (1);
}
