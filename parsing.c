/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:36:09 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/15 11:59:51 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block_based.h"
#include "chunk_sort.h"
#include "push_swap.h"
#include "radix.h"
#include "ft_printf.h"
#include <unistd.h>

static void	display_bench(float disorder, int strat, t_actions *a, int algo)
{
	int	disorder_first;
	int	disorder_last;

	disorder_first = disorder * 100;
	disorder_last = disorder * 10000 - disorder_first * 100;
	ft_printf("[bench] disorder: %d.%d%%\n", disorder_first, disorder_last);
	if (strat == 1)
		ft_printf("[bench] strategy: Simple O(n²)\n");
	else if (strat == 2)
		ft_printf("[bench] strategy: Medium O(n√n)\n");
	else if (strat == 3)
		ft_printf("[bench] strategy: Complex O(n log n)\n");
	else if (strat == 0)
	{
		ft_printf("[bench] strategy: Adaptive ");
		if (algo == 1)
			ft_printf("O(n²)\n");
		if (algo == 2)
			ft_printf("O(n√n)\n");
		if (algo == 3)
			ft_printf("(n log n)\n");
	}
	ft_printf("[bench] total_ops: %d\n", a->nb_op);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		get_action(a->lst, 0), get_action(a->lst, 1), get_action(a->lst, 2),
		get_action(a->lst, 3), get_action(a->lst, 4));
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		get_action(a->lst, 5), get_action(a->lst, 6), get_action(a->lst, 7),
		get_action(a->lst, 8), get_action(a->lst, 9), get_action(a->lst, 10));
}
//0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr

static int	set_strategy(t_options *opt, int value, int *c)
{
	*c += 1;
	if (opt->strategy != 0)
		return (-1);
	opt->strategy = value;
	return (0);
}

int	get_nb_args(char **argv, t_options *opt)
{
	int	i;
	int	c;

	c = 1;
	i = 0;
	while (argv[++i])
	{
		if (!ft_strncmp(argv[i], "--simple", 9))
		{
			if (set_strategy(opt, 1, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--medium", 9))
		{
			if (set_strategy(opt, 2, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--complex", 10))
		{
			if (set_strategy(opt, 3, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--adaptive", 11))
		{
			if (set_strategy(opt, 0, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--bench", 8))
		{
			opt->display = 1;
			c++;
		}
		else if (is_arg_number(argv[i]))
			continue ;
		else
			return (-1);
	}
	return (c);
}

int	get_actions(int (*f)(t_stacks*, t_actions*), t_stacks stack, t_actions a)
{
	int	*temp_tab;
	int	err;

	temp_tab = malloc(sizeof(int) * stack.size_a);
	if (!temp_tab)
		return (-1);
	ft_memcpy(temp_tab, stack.tab_a, stack.size_a);
	stack.tab_a = temp_tab;
	err = f(&stack, &a);
	free(temp_tab);
	ft_lstdelete(&a.lst);
	if (err == -1)
		return (-1);
	return (a.nb_op);
}

int	adaptive(t_stacks stack)
{
	int			chunk;
	int			radix_val;
	int			insertion;
	t_actions	a;

	a.nb_op = 0;
	a.lst = NULL;
	chunk = get_actions(chunk_sort, stack, a);
	radix_val = get_actions(radix, stack, a);
	insertion = get_actions(insertion_sort, stack, a);
	if (insertion == 1 || radix_val == 1 || chunk == 1)
		return (-1);
	if (chunk < radix_val && chunk < insertion)
		return (2);
	else if (radix_val < insertion)
		return (3);
	return (1);
}

int	choose_strategy(t_stacks *stack, t_actions *actions, t_options *opt)
{
	int		error;
	int		display;
	float	dis;
	int		algo;

	display = 0;
	dis = disorder(stack->tab_a, stack->size_a);
	error = 0;
	algo = 0;
	if (opt->strategy == 1)
		error = insertion_sort(stack, actions);
	else if (opt->strategy == 2)
		error = chunk_sort(stack, actions);
	else if (opt->strategy == 3)
		error = radix(stack, actions);
	else if (opt->strategy == 0)
	{
		algo = adaptive(*stack);
		if (algo == -1)
			return (-1);
		if (algo == 1)
			error = insertion_sort(stack, actions);
		else if (algo == 2)
			error = chunk_sort(stack, actions);
		else if (algo == 3)
			error = radix(stack, actions);
	}
	else
		return (-1);
	ft_lstprint(actions->lst);
	if (opt->display == 1)
		display_bench(dis, opt->strategy, actions, algo);
	ft_lstdelete(&actions->lst);
	return (error);
}

int	check_args(int argc, char **argv, int start)
{
	int	i;
	int	j;

	i = start;
	if (!argv[i])
		return (0);
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
	return (argc - 1);
}
