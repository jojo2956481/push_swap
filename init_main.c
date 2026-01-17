/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:35:39 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/17 09:35:42 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

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

int	init_tab(t_stacks *stacks, int max_size)
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

void	init_struct_action(t_actions *actions, t_options *opt)
{
	actions->nb_op = 0;
	actions->lst = NULL;
	opt->strategy = 0;
	opt->display = 0;
}
