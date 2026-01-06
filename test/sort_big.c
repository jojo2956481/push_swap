#include "push_swap.h"

static int find_max(int *b, int size)
{
	int i;
	int max;
	int idx;

	max = b[0];
	idx = 0;
	i = 1;
	while (i < size)
	{
		if (b[i] > max)
		{
			max = b[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

void push_swap_sort(int *a, int *b, int *size_a, int *size_b)
{
	int i = 0;
	int chunk = (*size_a <= 100) ? 15 : 35;
	int limit = chunk;

	if (is_sorted(a, *size_a))
		return;
	if (*size_a <= 3)
		return (sort_small(a, b, size_a, size_b));
	while (*size_a)
	{
		if (a[0] <= i)
		{
			pb(a, b, size_a, size_b);
			rb(b, *size_b);
			i++;
		}
		else if (a[0] <= limit)
		{
			pb(a, b, size_a, size_b);
			i++;
		}
		else
			ra(a, *size_a);
		if (i == limit)
			limit += chunk;
	}
	while (*size_b)
	{
		int idx = find_max(b, *size_b);
		if (idx <= *size_b / 2)
			while (idx--)
				rb(b, *size_b);
		else
			while (idx++ < *size_b - 1)
				rrb(b, *size_b);
		pa(a, b, size_a, size_b);
	}
}
