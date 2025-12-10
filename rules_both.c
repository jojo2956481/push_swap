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

// sa and sb at the same time.
int	ss(int *b, int *a, int size_a, int size_b)
{
	if (size_a <= 1 || size_b <= 1)
		return (0);
	SB(b, size);
	SA(a, size);
	return (1);
}

// ra and rb at the same time.
int	rr(int *b, int *a, int size_b, int size_a)
{
	if (size_b < 2 || size_a < 2)
		return (0);
	rb(int *b, int size_b);
	ra(int *a, int size_a);
	return (0);
}

// rra and rrb at the same time.
int	rrr(int *b, int *a, int size_b, int size_a)
{
	if (size_b < 2 || size_a < 2)
		return (0);
	rrb(int *b, int size_b);
	rra(int *a, int size_a);
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	int     tab[10] = {0, 4, 7, 5, 6, 2, 9, 8, 3, 10};
// 	int     size;
// 	int     i;

// 	size = 10;
// 	i = 0;
// 	rra(tab, size);
// 	while (i < size)
// 	{
// 			printf("%d", tab[i]);
// 			i++;
// 	}
// 	return (0);
// }