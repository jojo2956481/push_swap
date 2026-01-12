#include "libft.h"
#include "block_based.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

int choose_strategy(char **argv, int *tab_a, int *tab_b, int size_a)
{
	int size_b;
	int nb_op;
	int display_data;

	display_data = 0;
	size_b = 0;
	nb_op = 0;
	if (ft_strncmp(argv[1], "--simple", 9) == 0)
		nb_op = block_sort(tab_a, tab_b, &size_a, &size_b);
	else if (ft_strncmp(argv[1], "--medium", 9) == 0)
		nb_op = block_sort(tab_a, tab_b, &size_a, &size_b);
	else if (ft_strncmp(argv[1], "--complex", 10) == 0)
		nb_op = block_sort(tab_a, tab_b, &size_a, &size_b);
	else if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
		nb_op = block_sort(tab_a, tab_b, &size_a, &size_b);
	else if (ft_strncmp(argv[1], "--bench", 11) == 0)
		display_data = 1;
	else if (is_arg_number(argv[1]))
		nb_op = block_sort(tab_a, tab_b, &size_a, &size_b);
	else
	{
		return (free_all(NULL, NULL, -1, 1));
	}
	return (nb_op);
}
int	check_args(int argc, char **argv, int start)
{
	int j;
	int i;

	i = start;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (free_all(NULL, NULL, 0, 1));
			j++;
		}
		i++;
	}
	return (i);
}