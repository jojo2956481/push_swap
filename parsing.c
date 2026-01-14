/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:36:09 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/14 14:41:08 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block_based.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

static void	display_bench(float disorder, char *strat, t_actions *acts)
{
	int	disorder_first;
	int	disorder_last;

	disorder_first = disorder * 100;
	disorder_last = disorder * 10000 - disorder_first * 100;
	ft_printf("[bench] disorder:  %d.%d%%\n", disorder_first, disorder_last);
	ft_printf("[bench] strategy:  %s\n", strat);
	ft_printf("[bench] total_ops: %d\n", acts->nb_op);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		get_nb_action_by_type(acts->lst, 0), get_nb_action_by_type(acts->lst, 1), get_nb_action_by_type(acts->lst, 2),
		get_nb_action_by_type(acts->lst, 3), get_nb_action_by_type(acts->lst, 4));
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		get_nb_action_by_type(acts->lst, 5), get_nb_action_by_type(acts->lst, 6), get_nb_action_by_type(acts->lst, 7),
		get_nb_action_by_type(acts->lst, 8), get_nb_action_by_type(acts->lst, 9), get_nb_action_by_type(acts->lst, 10));
}
// 0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr

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
			if (set_strategy(opt, 4, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--medium", 9))
		{
			if (set_strategy(opt, 4, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--complex", 10))
		{
			if (set_strategy(opt, 4, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--adaptive", 11))
		{
			if (set_strategy(opt, 4, &c) == -1)
				return (-1);
		}
		else if (!ft_strncmp(argv[i], "--bench", 8))
		{
			opt->display = 1;
			c++;
		}
		else if (is_arg_number(argv[i]))
			opt->strategy = 0;
		else
			return (-1);
	}
	return (c);
}

int	choose_strategy(t_stacks *stack, t_actions *actions, t_options *opt)
{
	int nb_op;
	int	display;
	float disorder = 0.54632;

	display = 0;
	nb_op = 0;
	if (opt->strategy == 1)
		nb_op = insertion_sort(stack, actions);
	else if (opt->strategy == 2)
		nb_op = chunk_sort(stack, actions);
	else if (opt->strategy == 3)
		nb_op = radix(stack, actions);
	else if (opt->strategy == 4)
		nb_op = block_sort(stack, actions);
	else if (opt->strategy == 0)
		nb_op = chunk_sort(stack, actions);
	else
		return (free_all(stack->tab_a, stack->tab_b, -1, 1));
	if (opt->display == 1)
		display_bench(disorder, "static", actions);
	return (nb_op);
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
