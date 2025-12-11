/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:11:09 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/11 08:11:11 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *min_heap, int nb_block, int *pos, int *idx_min)
{
	int	min;
	int	i;

	i = 1;
	*idx_min = 0;
	min = min_heap[0];
	while (i < nb_block)
	{
		if (pos[i] < 3 && min_heap[i] < min)
		{
			min = min_heap[i];
			*idx_min = i;
		}
		i++;
	}
	return (min);
}

int	filling_output(int *pos, int *tab, int idx_min, int size_tab)
{
	int	block_start;
	int	next_index;

	pos[idx_min]++;
	block_start = idx_min * 3;
	next_index = block_start + pos[idx_min];
	if (next_index < size_tab)
		return (tab[next_index]);
	else
		return (2147483647);
}

int	output_management(int size_tab, int *min_heap, int *tab, int *tab_output)
{
	int	nb_block;
	int	*pos;
	int	idx_min;
	int	i;
	int	j;

	j = 0;
	i = 0;
	nb_block = size_tab / 3;
	if (size_tab % 3 != 0)
		nb_block++;
	init_min_heap(tab, size_tab, min_heap);
	pos = init_pos(nb_block);
	if (!pos)
		return (0);
	i = 0;
	while (i < size_tab)
	{
		tab_output[i++] = find_min(min_heap, nb_block, pos, &idx_min);
		min_heap[idx_min] = filling_output(pos, tab, idx_min, size_tab);
	}
	free(pos);
	return (1);
}

void	sorting_blocks(int size_tab, int *tab)
{
	int	i;
	int	end;

	i = 0;
	while (i < size_tab)
	{
		end = i + 3;
		if (end > size_tab)
			end = size_tab;
		bubble_sort(&tab[i], end - i);
		i += 3;
	}
}

int	*block_sort(int *tab, int size_tab)
{
	int	*min_heap;
	int	*tab_output;
	int	nb_block;

	nb_block = size_tab / 3;
	if (size_tab % 3 != 0)
		nb_block++;
	tab_output = malloc(sizeof(int) * size_tab);
	if (!tab_output)
		return (NULL);
	min_heap = (int *)malloc(sizeof(int) * (nb_block));
	if (!min_heap)
		return (free(tab_output), NULL);
	sorting_blocks(size_tab, tab);
	if (output_management(size_tab, min_heap, tab, tab_output) == 0)
		return (free(min_heap), free(tab_output), NULL);
	free(min_heap);
	return (tab_output);
}
/*
#include <stdio.h>
int main(void)
{
	int tab[8] = {1, 8, 7, 2, 3, 5, 4, 6};
	int	*tab_output;
	tab_output = block_sort(tab, 8);

	for (int i = 0; i < 8; i++)
		printf(" %d |", tab_output[i]);
	free(tab_output);
	return 0;
}*/
