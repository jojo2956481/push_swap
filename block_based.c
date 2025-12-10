#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int find_min(int *min_heap, int nb_block, int *pos, int *idx_min)
{
	int min;
	int i;

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

void	filling_output(int *min_heap, int *pos, int *tab, int idx_min, int size_tab)
{
	pos[idx_min]++;
	int block_start = idx_min * 3;
	int next_index = block_start + pos[idx_min];
	if (next_index < size_tab)
		min_heap[idx_min] = tab[next_index];
	else
		min_heap[idx_min] = 2147483647;
}

int	*output_management(int size_tab, int *min_heap, int *tab, int *tab_output)
{
	int	nb_block;
	int *pos;
	int idx_min;
	int	i;
	int	j;

	j = 0;
	i = 0;
	nb_block = size_tab / 3;
	if (size_tab % 3 != 0)
		nb_block++;
	while (i < size_tab)
	{
		min_heap[j++] = tab[i];
		i += 3;
	}
	pos = malloc(sizeof(int) * nb_block);
	i = 0;
	while (i < nb_block)
		pos[i++] = 0;
	i = 0;
	while (i < size_tab)
	{
		tab_output[i++] = find_min(min_heap, nb_block, pos, &idx_min);
		filling_output(min_heap, pos, tab, idx_min, size_tab);
	}
	free(min_heap);
	free(pos);
	return (tab_output);
}

int *block_sort(int *tab, int size_tab)
{
	int	*min_heap;
	int i = 0;
	int	*tab_output;
	int	nb_block = size_tab / 3;

	if (size_tab % 3 != 0)
		nb_block++;
	tab_output = malloc(sizeof(int) * size_tab);
	min_heap = (int *)malloc(sizeof(int) * (size_tab / 3));
	while (i < size_tab)
	{
		int end = i + 3;
		if (end > size_tab)
			end = size_tab;
		bubble_sort(&tab[i], end - i);
		i += 3;
	}
	i = 0;
	output_management(size_tab, min_heap, tab, tab_output);
	return (tab_output);
}

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
}