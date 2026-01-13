/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 09:49:30 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block_based.h"
#include "get_next_line.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int free_all(int *a, int *b, int return_value, int error)
{
	int i;

	i = 0;
	if (a)
		free(a);
	if (b)
		free(b);
	if (error)
		write(2, "Error\n", 6);
	return (return_value);
}

int	is_arg_number(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

static int  set_strategy(t_options *opt, int value, int *c)
{
	*c += 1;
    if (opt->strategy != 0)
        return (-1);
    opt->strategy = value;
    return (0);
}

int get_nb_args(char **argv, t_options *opt)
{
    int i;
	int c;

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

int	fill_tab(int *tab, char **str, int start)
{
	int	i;
	int	x;

	x = 0;
	i = start;
	while (str[i] != NULL)
	{
		if (!is_arg_number(str[i]))
			return (0);
		tab[x] = ft_atoi(str[i]);
		if (ft_atoi(str[i]) < INT_MIN || ft_atoi(str[i]) > INT_MAX)
			return (0);
		x++;
		i++;
	}
	return (1);
}

int init_tab(t_stacks *stacks, int max_size)
{
	stacks->size_a = max_size;
	stacks->size_b = 0;
	stacks->tab_a = ft_calloc(max_size, sizeof(int));
	if (!stacks->tab_a)
		return (1);
	stacks->tab_b = ft_calloc(max_size, sizeof(int));
	if (!stacks->tab_b)
	{
		free(stacks->tab_a);
		return (1);
	}
	return (0);
}

void init_struct_action(t_actions *actions, t_options *opt)
{
	actions->nb_op = 0;
	actions->sa = 0;
	actions->ra = 0;
	actions->rra = 0;
	actions->pb = 0;
	actions->sb = 0;
	actions->rb = 0;
	actions->rrb = 0;
	actions->ss = 0;
	actions->rr = 0;
	actions->rrr = 0;
	opt->strategy = 0;
	opt->display = 0;
}

int main(int argc, char **argv)
{
	t_stacks 	stacks;
	int     	size;
	int     	offset;
	t_actions	actions;
	t_options	opt;

	actions.pa = 0;
	if (argc <= 1)
		return (free_all(NULL, NULL, 1, 1));
	init_struct_action(&actions, &opt);
	offset = get_nb_args(argv, &opt);
	if (offset == -1)
		return (free_all(NULL, NULL, 1, 1));
	size = check_args(argc - (offset - 1), argv, offset);
	if (size <= 0)
		return (write(2, "Error\n", 6), 1);
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, argv, offset) == 0)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	int i = 0;
	while (i < stacks.size_a)
	{
		__builtin_printf("%d\n", stacks.tab_a[i]);
		i++;
	}
	if (choose_strategy(&stacks, &actions, &opt) == -1)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	return (free_all(stacks.tab_a, stacks.tab_b, 0, 0));
}