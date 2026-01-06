/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:11:09 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/11 08:11:11 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "block_based.h"
#include <stdlib.h>

int find_min_cpy(int *min_heap, int nb_block, int *pos, int *idx_min)
{
	int min = 2147483647;
	int i = 0;

	*idx_min = -1;
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

int filling_output_cpy(int *pos, int *tab, int idx_min, int size_tab)
{
	int    block_start;
	int    next_index;

	if (idx_min == -1)
		return (2147483647);

	pos[idx_min]++;
	block_start = idx_min * 3;
	next_index = block_start + pos[idx_min];
	if (next_index < size_tab && next_index < (idx_min * 3) + 3)
		return (tab[next_index]);
	else
		return (2147483647);
}

int output_management_cpy(int size_tab, int *min_heap, int *tab, int *tab_output)
{
	int    nb_block;
	int    *pos;
	int    idx_min;
	int    i;

	nb_block = (size_tab + 2) / 3;
	init_min_heap_cpy(tab, size_tab, min_heap);
	pos = init_pos_cpy(nb_block);
	if (!pos)
		return (0);

	i = 0;
	while (i < size_tab)
	{
		tab_output[i++] = find_min_cpy(min_heap, nb_block, pos, &idx_min);
		if (idx_min != -1)
			min_heap[idx_min] = filling_output_cpy(pos, tab, idx_min, size_tab);
	}
	free(pos);
	return (1);
}

void	sorting_blocks_cpy(int size_tab, int *tab)
{
	int	i;
	int	end;

	i = 0;
	while (i < size_tab)
	{
		end = i + 3;
		if (end > size_tab)
			end = size_tab;
		bubble_sort_cpy(&tab[i], end - i);
		i += 3;
	}
}

int	*block_sort_without_rules(int *cpy_tab, int size_tab)
{
	//int	*min_heap;
	int	*tab_output;
	int	nb_block;
	int i;

	i = 0;
	nb_block = size_tab / 3;
	if (size_tab % 3 != 0)
		nb_block++;
	tab_output = malloc(sizeof(int) * size_tab);
	if (!tab_output)
		return (NULL);
	sorting_blocks_cpy(size_tab, cpy_tab);
	while (i < size_tab)
	{
		tab_output[i] = cpy_tab[i];
		i++;
	}
	return (tab_output);
}
/*
int main(void)
{
	int tab_a[] = {5,6,3,8,9,6,7,1,1,2, 9};
	int *tab_b;
	int size_a = 10;
	int size_b = 0;
	int i = 0;

	tab_b = block_sort_without_rules(tab_a, size_a);
	while (i < size_a)
	{
		__builtin_printf("%d\n", tab_b[i]);
		i++;
	}
	free(tab_b);
}*/