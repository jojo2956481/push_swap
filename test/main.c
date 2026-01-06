#include "push_swap.h"

static int  check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int size_a;
	int size_b;
	int i;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		ft_error();
	size_a = argc - 1;
	size_b = 0;
	a = malloc(sizeof(int) * size_a);
	b = malloc(sizeof(int) * size_a);
	if (!a || !b)
		ft_error();
	i = 0;
	while (i < size_a)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	index_stack(a, size_a);
	push_swap_sort(a, b, &size_a, &size_b);
	while (size_a > 0)
		__builtin_printf("%d\n", a[--size_a]);
	free(a);
	free(b);
	return (0);
}
