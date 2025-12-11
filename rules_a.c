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
	//static int	count = 0;

	//printf("%d : sa\n", ++count);
	if (size_a <= 1)
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (1);
}

// Take the first element at the top of b and put it at the top of a.
int	pa(int *a, int *b, int size_a, int size_b)
{
	int	i;

	i = 0;
	if (size_b <= 0 || size_a <= 0)
		return (0);
	if (!b[0])
		return (0);
	while (size_a--)
		a[size_a] = a[size_a - 1];
	a[0] = b[0];
	while (++size_a < size_b - 1)
		b[size_a] = b[size_a + 1];
	return (1);
}

// Shift up all elements of stack a by one
int	ra(int *a, int size_a)
{
	int	temp;
	int	i;
	//static int	count = 0;

	//printf("%d : ra\n", ++count);
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

int main(void)
{
	int tab_a[10] = {1,2,3,4,5};
	int tab_b[10] = {11,22,33,44,55};
 	pa(tab_a, tab_b, 10, 10);
	int i = 0;
	__builtin_printf("|----------------|\n");
	__builtin_printf("| tab_a    tab_b |\n");
	__builtin_printf("|----------------|\n");
	while (i < 10)
	{
		__builtin_printf("|% 4d   | % 4d   |\n", tab_a[i], tab_b[i]);
		i++;
	}
	return (0);
}
