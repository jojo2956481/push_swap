#include "push_swap.h"

void index_stack(int *a, int size)
{
	int i;
	int j;
	int count;
	int *indexed;

	indexed = malloc(sizeof(int) * size);
	if (!indexed)
		ft_error();
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (a[j] < a[i])
				count++;
			j++;
		}
		indexed[i] = count;
		i++;
	}
	i = 0;
	while (i < size)
	{
		a[i] = indexed[i];
		i++;
	}
	free(indexed);
}
