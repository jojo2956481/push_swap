/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:00:09 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/17 11:56:37 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	copy_tab_radix(int *tab_a, int *tab_sort, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab_sort[i] = tab_a[i];
		i++;
	}
}

void	indexation(int *tab_sort, int *tab, int *tab_index, int size)
{
	int	i;
	int	y;

	y = 0;
	while (y < size)
	{
		i = 0;
		while (tab[y] != tab_sort[i])
			i++;
		tab_index[y] = i;
		y++;
	}
}

int	init_bit_max(int *tab_sort, int size)
{
	int	max_index;
	int	max_bit;

	max_bit = 0;
	max_index = tab_sort[size - 1];
	while ((max_index >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

int is_sorted(int *tab_a, int size)
{
	int i;
	i = 0;
	while (i < size - 1)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}