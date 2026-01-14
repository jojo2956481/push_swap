/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils_find.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:47:36 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 15:53:51 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "chunk_sort.h"

int	find_max(int *tab_sort, int *tab_b, int size_b, int chunk_size)
{
	int i;
	int j;

	i = chunk_size - 1;
	while (i > -1)
	{
		j = 0;
		while (j < size_b)
		{
			if (tab_sort[i] == tab_b[j])
				return (j);
			j++;
		}
		i--;
	}
	// ft_printf("j = %d\n", j);
	return (j);
}

int	find_index(int *shunk, int size, int value);
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (shunk[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max_value(int *tab_b, int size_b)
{
	int	i;
	int	max;

	i = 0;
	max = tab_b[0];
	while (i < size_b)
	{
		if (tab_b[i] > max)
			max = tab_b[i];
		i++;
	}
	return (max);
}