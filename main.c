/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 16:29:02 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;
	t_actions	actions;
	t_options	opt;
	char		**args;

	if (argc <= 1)
		return (0);
	init_struct_action(&actions, &opt);
	args = parse_args(argc, argv, get_nb_args(argv, &opt));
	if (!args || !args[0])
		return (free_all(NULL, NULL, 1, 1));
	size = check_args(args);
	if (size <= 0)
		return (free_all(NULL, args, 1, 1));
	if (init_tab(&stacks, size) == 1)
		return (free_all(&stacks, args, 1, 1));
	if (fill_tab(stacks.tab_a, args) == 0)
		return (free_all(&stacks, args, 1, 1));
	if (stacks.size_a == 3)
	{
		sort_3(&stacks, &actions, 0);
		return (free_all(&stacks, args, 0, 0));
	}
	if (stacks.size_a == 5)
	{
		sort_5(&stacks, &actions, 0);
		return (free_all(&stacks, args, 0, 0));
	}
	if (!is_sorted(stacks.tab_a, stacks.size_a))
	{
		if (choose_strategy(&stacks, &actions, &opt) == -1)
			return (free_all(&stacks, args, 1, 1));
	}
	return (free_all(&stacks, args, 0, 0));
}
