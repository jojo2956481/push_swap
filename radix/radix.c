/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:13:11 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 10:05:57 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "radix.h"

void	radix_sort(t_stacks *stack, t_actions *actions,
		int *tab_sort, int *tab_index)
{
	int	size;
	int	bit;
	int	max_bit;
	int	i;

	size = stack->size_a;
	max_bit = init_bit_max(tab_sort, size);
	bit = -1;
	while (++bit < max_bit)
	{
		i = -1;
		while (++i < size)
		{
			if (((tab_index[i] >> bit) & 1) == 0)
				pb(stack, actions);
			else
				ra(stack->tab_a, stack->size_a, actions);
		}
		while (stack->size_b > 0)
			pa(stack, actions);
		if (is_sorted(stack->tab_a, stack->size_a) == 1)
			break ;
		indexation(tab_sort, stack->tab_a, tab_index, size);
	}
}

int	radix(t_stacks *stack, t_actions *actions)
{
	int	*tab_sort;
	int	*tab_index;
	int	size;

	size = stack->size_a;
	tab_sort = ft_calloc(size, sizeof(int));
	if (tab_sort == NULL)
		return (free_all(NULL, NULL, 1, 1));
	tab_index = ft_calloc(size, sizeof(int));
	if (tab_index == NULL)
		return (free_all(tab_sort, NULL, 1, 1));
	copy_tab_radix(stack->tab_a, tab_sort, size);
	sort_tab(tab_sort, size);
	indexation(tab_sort, stack->tab_a, tab_index, size);
	radix_sort(stack, actions, tab_sort, tab_index);
	return (free_all(tab_sort, tab_index, 0, 0));
}
