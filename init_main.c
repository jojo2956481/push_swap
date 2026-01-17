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

char	*join_args(int argc, char **argv, int start)
{
	char	*tmp;
	char	*joined;
	int		i;

	i = start;
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		if (!tmp)
			return (NULL);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		if (!joined)
			return (NULL);
		i++;
	}
	return (joined);
}

char	**parse_args(int argc, char **argv, int start)
{
	char	*big_string;
	char	**clean_args;

	if (start == -1)
		return (NULL);
	big_string = join_args(argc, argv, start);
	if (!big_string)
		return (NULL);
	clean_args = ft_split(big_string, ' ');
	free(big_string);
	return (clean_args);
}

int	fill_tab(int *tab, char **str)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
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
