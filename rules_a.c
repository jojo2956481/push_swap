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

// Swap the first two elements at the top of stack a
int	sa(int *a, int size_a)
{
	int	temp;

	if (size_a <= 1)
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (1);
}

// Take the first element at the top of b and put it at the top of a.
int	pa(int *b, int *a, int size_b, int size_a)
{
	if (size_b <= 0 || size_a <= 0)
		return (0);
	if (!b[0])
		return (0);
	a[0] = b[0];
	return (1);
}

// Shift up all elements of stack a by one
int	ra(int *a, int size_a)
{
	int	temp;
	int	i;

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
int	rra(int *a, int size_a)
{
	int	temp;
	int	i;

	if (size_a < 2)
		return (0);
	temp = a[size_a - 1];
	i = size_a - 1;
	while (i >= 1)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	return (1);
}
