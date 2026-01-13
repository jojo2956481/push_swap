#include "libft.h"
#include "block_based.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

void	display_bench(float disorder, char *strat, t_actions *acts)
{
	int	disorder_first;
	int	disorder_last;

	disorder_first = disorder * 100;
	disorder_last = disorder * 10000 - disorder_first * 100;
	ft_printf("[bench] disorder:  %d.%d%%\n", disorder_first, disorder_lat);
	ft_printf("[bench] strategy:  %s\n", strat);
	ft_printf("[bench] total_ops: %d\n", acts->nb_op);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		acts->sa, acts->sb, acts->ss, acts->pa, acts->pb);
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		acts->ra, acts->rb, acts->rr, acts->rra, acts->rrb, acts->rrr);
}

int choose_strategy(char **argv, t_stacks *stack, t_actions *actions)
{
	int nb_op;
	int	display;

	display = 0;
	nb_op = 0;
	if (ft_strncmp(argv[1], "--simple", 9) == 0)
		nb_op = block_sort(stack, actions);
	else if (ft_strncmp(argv[1], "--medium", 9) == 0)
		nb_op = block_sort(stack, actions);
	else if (ft_strncmp(argv[1], "--complex", 10) == 0)
		nb_op = block_sort(stack, actions);
	else if (ft_strncmp(argv[1], "--adaptive", 11) == 0)
		nb_op = block_sort(stack, actions);
	else if (ft_strncmp(argv[1], "--bench", 8) == 0)
		display = 1;
	else if (is_arg_number(argv[1]))
		nb_op = block_sort(stack, actions);
	else
		return (free_all(stack->tab_a, stack->tab_b, -1, 1));
	if (display == 1)

	return (nb_op);
}

int check_args(int argc, char **argv, int start)
{
	int i;
	int j;

	i = start;
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
	return (argc - start);
}