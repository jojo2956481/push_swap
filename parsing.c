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

//0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr
static int	set_strategy(t_options *opt, int value, int *c)
{
	*c += 1;
	if (opt->strategy != 0)
		return (-1);
	opt->strategy = value;
	return (0);
}

static int	handle_strategy_flags(char *arg, t_options *opt, int *c)
{
	if (!ft_strncmp(arg, "--simple", 9))
		return (set_strategy(opt, 1, c));
	else if (!ft_strncmp(arg, "--medium", 9))
		return (set_strategy(opt, 2, c));
	else if (!ft_strncmp(arg, "--complex", 10))
		return (set_strategy(opt, 3, c));
	else if (!ft_strncmp(arg, "--adaptive", 11))
		return (set_strategy(opt, 0, c));
	else if (!ft_strncmp(arg, "--bench", 8))
	{
		opt->display = 1;
		(*c)++;
		return (0);
	}
	return (1);
}

int	get_nb_args(char **argv, t_options *opt)
{
	int	i;
	int	c;
	int	res;

	c = 1;
	i = 0;
	while (argv[++i])
	{
		res = handle_strategy_flags(argv[i], opt, &c);
		if (res == -1)
			return (-1);
		if (res == 1)
		{
			if (!is_arg_number(argv[i]))
				return (-1);
		}
	}
	return (c);
}

int	choose_strategy(t_stacks *stack, t_actions *actions, t_options *opt)
{
	int		error;
	float	dis;
	int		algo;

	dis = disorder(stack->tab_a, stack->size_a);
	algo = opt->strategy;
	if (opt->strategy == 0)
	{
		algo = adaptive(*stack);
		if (algo == -1)
			return (-1);
	}
	error = execute_algo(algo, stack, actions);
	if (error != -1)
	{
		ft_lstprint(actions->lst);
		if (opt->display == 1)
			display_bench(dis, opt->strategy, actions, algo);
		ft_lstdelete(&actions->lst);
	}
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
