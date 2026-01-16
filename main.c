/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 09:26:19 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "block_based.h"
#include "get_next_line.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int	free_all(int *a, int *b, int return_value, int error)
{
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
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

static int	fill_tab(int *tab, char **str, int start)
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

static int	init_tab(t_stacks *stacks, int max_size)
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

static void	init_struct_action(t_actions *actions, t_options *opt)
{
	actions->nb_op = 0;
	actions->lst = NULL;
	opt->strategy = 0;
	opt->display = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;
	int			offset;
	t_actions	actions;
	t_options	opt;

	if (argc <= 1)
		return (free_all(NULL, NULL, 1, 1));
	init_struct_action(&actions, &opt);
	offset = get_nb_args(argv, &opt);
	if (offset == -1)
		return (free_all(NULL, NULL, 1, 1));
	size = check_args(argc - (offset - 1), argv, offset);
	if (size <= 0)
		return (free_all(NULL, NULL, 1, 1));
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, argv, offset) == 0)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	if (choose_strategy(&stacks, &actions, &opt) == -1)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	return (free_all(stacks.tab_a, stacks.tab_b, 0, 0));
}
