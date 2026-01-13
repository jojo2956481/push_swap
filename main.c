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

int	fill_tab(int *tab, int size_tab, char **str, int start)
{
	int	i;
	int	x;

	x = 0;
	i = start;
	while (x < size_tab)
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

void init_struct_action(t_actions *actions)
{
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
}

int main(int argc, char **argv)
{
	t_stacks 	stacks;
	int     	size;
	int     	offset;
	t_actions	actions;

	actions.pa = 0;
	if (argc <= 1)
		return (1);
	if (argv[1][0] == '-')
		offset = 2;
	else
		offset = 1;
	size = check_args(argc - (offset - 1), argv, offset);
	if (size <= 0)
		return (write(2, "Error\n", 6), 1);
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, size, argv, offset) == 0)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	init_struct_action(&actions);
	if (choose_strategy(argv, &stacks, &actions) == -1)
	{
		free(stacks.tab_a);
		free(stacks.tab_b);
		return (1);
	}
	free(stacks.tab_a);
	free(stacks.tab_b);
	return (0);
}