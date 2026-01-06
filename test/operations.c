#include "push_swap.h"

void sa(int *a, int size)
{
	int tmp;

	if (size < 2)
		return;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	ft_putstr("sa\n");
}

void ra(int *a, int size)
{
	int tmp;
	int i;

	if (size < 2)
		return;
	tmp = a[0];
	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[size - 1] = tmp;
	ft_putstr("ra\n");
}

void rra(int *a, int size)
{
	int tmp;
	int i;

	if (size < 2)
		return;
	tmp = a[size - 1];
	i = size - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
	ft_putstr("rra\n");
}

void pb(int *a, int *b, int *size_a, int *size_b)
{
	int i;

	if (*size_a == 0)
		return;
	i = *size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_a)--;
	(*size_b)++;
	ft_putstr("pb\n");
}

void pa(int *a, int *b, int *size_a, int *size_b)
{
	int i;

	if (*size_b == 0)
		return;
	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_b)--;
	(*size_a)++;
	ft_putstr("pa\n");
}

void rb(int *b, int size)
{
	int tmp;
	int i;

	if (size < 2)
		return;
	tmp = b[0];
	i = 0;
	while (i < size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[size - 1] = tmp;
	ft_putstr("rb\n");
}

void rrb(int *b, int size)
{
	int tmp;
	int i;

	if (size < 2)
		return;
	tmp = b[size - 1];
	i = size - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
	ft_putstr("rrb\n");
}
