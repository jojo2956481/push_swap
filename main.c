/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/17 16:08:52 by lebeyssa         ###   ########lyon.fr   */
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
		return (free_all(NULL, NULL, 1, 1));
	init_struct_action(&actions, &opt);
	args = parse_args(argc, argv, get_nb_args(argv, &opt));
	if (!args || !args[0])
		return (free_all(NULL, NULL, 1, 1));
	size = check_args(args);
	if (size <= 0)
		return (free_all(NULL, NULL, 1, 1));
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, args) == 0)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	if (choose_strategy(&stacks, &actions, &opt) == -1)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	free_split(args);
	return (free_all(stacks.tab_a, stacks.tab_b, 0, 0));
}
