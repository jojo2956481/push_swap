#include "push_swap.h"

static void sort_3(int *a)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(a, 3);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sa(a, 3);
		rra(a, 3);
	}
	else if (a[0] > a[1] && a[0] > a[2])
		ra(a, 3);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(a, 3);
		ra(a, 3);
	}
	else if (a[0] < a[1] && a[0] > a[2])
		rra(a, 3);
}

void sort_small(int *a, int *b, int *size_a, int *size_b)
{
	if (*size_a == 2 && a[0] > a[1])
		sa(a, 2);
	else if (*size_a == 3)
		sort_3(a);
	(void)b;
	(void)size_b;
}
