#include "push_swap.h"
#include "block_based.h"

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min(int *tab, int size)
{
	int	i;
	int	min;
	int	idx;

	min = tab[0];
	idx = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}
void	sort_2(int *a)
{
	if (a[0] > a[1])
		sa(a, 2);
}
void	sort_3(int *a)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(a, 3);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sa(a, 3);
		rra(a, 3);
	}
	else if (a[0] > a[1] && a[1] < a[2])
		ra(a, 3);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(a, 3);
		ra(a, 3);
	}
	else if (a[0] < a[1] && a[1] > a[2])
		rra(a, 3);
}
void	sort_4(int *a, int *b, int *size_a, int *size_b)
{
	int	idx;

	idx = find_min(a, *size_a);
	if (idx == 1)
		ra(a, *size_a);
	else if (idx == 2)
	{
		ra(a, *size_a);
		ra(a, *size_a);
	}
	else if (idx == 3)
		rra(a, *size_a);
	pb(a, b, size_a, size_b);
	sort_3(a);
	pa(a, b, size_a, size_b);
}
void	sort_5(int *a, int *b, int *size_a, int *size_b)
{
	int	idx;

	idx = find_min(a, *size_a);
	if (idx == 1)
		ra(a, *size_a);
	else if (idx == 2)
	{
		ra(a, *size_a);
		ra(a, *size_a);
	}
	else if (idx == 3)
	{
		rra(a, *size_a);
		rra(a, *size_a);
	}
	else if (idx == 4)
		rra(a, *size_a);
	pb(a, b, size_a, size_b);
	sort_4(a, b, size_a, size_b);
	pa(a, b, size_a, size_b);
}

void	sort_small(int *a, int *b, int *size_a, int *size_b)
{
	if (*size_a == 2)
		sort_2(a);
	else if (*size_a == 3)
		sort_3(a);
	else if (*size_a == 4)
		sort_4(a, b, size_a, size_b);
	else if (*size_a == 5)
		sort_5(a, b, size_a, size_b);
}
