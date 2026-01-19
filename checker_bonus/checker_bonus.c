/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:24:27 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/19 10:36:26 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;
	int			nb;
	t_actions	actions;
	char		**args;

	if (argc <= 1)
		return (0);
	actions.nb_op = 0;
	args = parse_args(argc, argv, 1);
	size = check_args(args);
	if (size <= 0)
		return (0);
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, args) == 0)
		return (free_all(&stacks, args, 1, 1));
	if (!is_sorted(stacks.tab_a, stacks.size_a))
	{
		nb = read_standard_input(&stacks, &actions);
		if (nb == -1)
			return (free_all(&stacks, args, 1, 1));
	}
	if (is_sorted(stacks.tab_a, size) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_all(&stacks, args, 0, 0));
}
