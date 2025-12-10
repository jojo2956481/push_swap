#include <stdlib.h>
#include <stdio.h>
int find_min(int *min_heap, int nb_block, int *pos, int blocksize, int *idx_min)
{
	int min;
	int i;

	i = 1;
	*idx_min = 0;
	min = min_heap[0];
	while (i < nb_block)
	{
		if (pos[i] < blocksize && min_heap[i] < min)
		{
			min = min_heap[i];
			*idx_min = i;
		}
		i++;
	}
	return (min);
}
/*
int	filling_output(int *tab_output, int *pos, int blocksize, int *idx_min, int size_tab)
{
	tab_output[n++] = min;
	pos[idx_min]++;
	int block_start = idx_min * blocksize;
	int next_index = block_start + pos[idx_min];
	if (next_index < size_tab)
		min_heap[idx_min] = tab[next_index];
	else
		min_heap[idx_min] = 2147483647;
}
*/
int *block_sort(int *tab, int size_tab)
{
	int blocksize = 3;
	int	*min_heap;
	int i = 0;
	int j;
	int k;
	int	*tab_output;
	int	nb_block = size_tab / blocksize;
	if (size_tab % blocksize != 0)
		nb_block++;
	tab_output = malloc(sizeof(int) * size_tab);
	min_heap = (int *)malloc(sizeof(int) * (size_tab / blocksize));
	while (i < size_tab)
	{
		int end = i + blocksize;
		if (end > size_tab)
			end = size_tab;
		j = i;
		while (j < end)
		{
			k = i;
			while (k < end - 1)
			{
				if (tab[k] > tab[k + 1])
				{
					int tmp = tab[k];
					tab[k] = tab[k + 1];
					tab[k + 1] = tmp;
				}
				k++;
			}
			j++;
		}
		i += blocksize;
	}
	i = 0;
	j = 0;
	while (i < size_tab)
	{
		min_heap[j++] = tab[i];
		i += blocksize;
	}
	int *pos = malloc(sizeof(int) * nb_block);
	for (i = 0; i < nb_block; i++)
		pos[i] = 0;
	int n = 0;
	int	min;
	int idx_min;
	while (n < size_tab)
	{
		min = find_min(min_heap, nb_block, pos, blocksize, &idx_min);
		tab_output[n++] = min;
		pos[idx_min]++;
		int block_start = idx_min * blocksize;
		int next_index = block_start + pos[idx_min];
		if (next_index < size_tab)
			min_heap[idx_min] = tab[next_index];
		else
			min_heap[idx_min] = 2147483647;
		//filling_output(tab_output, pos, blocksize, idx_min, size_tab);
	}
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

	return 0;
}