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

// Swap the first two elements at the top of stack b
int	sb(int *b, int size_b)
{
	int	temp;

	if (size_b <= 1)
		return (0);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	return (1);
}

// Take the first element at the top of a and put it at the top of b.
int	pb(int *a, int *b, int size_a, int size_b)
{
	int	i;

	i = 0;
	if (size_b <= 0 || size_a <= 0)
		return (0);
	if (!a[0])
		return (0);
	while (size_b--)
		b[size_b] = b[size_b - 1];
	b[0] = a[0];
	while (++size_b < size_a - 1)
		a[size_b] = a[size_b + 1];
	return (1);
}

// Shift up all elements of stack b by one.
int	rb(int *b, int size_b)
{
	int	temp;
	int	i;

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
int	rrb(int *b, int size_b)
{
	int	temp;
	int	i;

	if (size_b < 2)
		return (0);
	temp = b[size_b - 1];
	i = size_b - 1;
	while (i >= 1)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	return (1);
}

int main(void)
{
	int tab_a[10] = {1,2,3,4,5};
	int tab_b[10] = {11,22,33,44,55};
	pb(tab_a, tab_b, 10, 10);
	int i = 0;
	__builtin_printf("|-----------------|\n");
	__builtin_printf("| tab_a     tab_b |\n");
	__builtin_printf("|-----------------|\n");
	while (i < 10)
	{
		__builtin_printf("|% 4d   || % 4d   |\n", tab_a[i], tab_b[i]);
		i++;
	}
	return (0);
}
