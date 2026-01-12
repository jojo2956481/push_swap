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

int init_tab(int **a, int **b, int *size_a, int *size_b)
{
	if (*size_a == 0)
		return (free_all(NULL, NULL, 1, 1));
	*a = ft_calloc(*size_a, sizeof(int));
	if (*a == NULL)
		return (free_all(NULL, NULL, 1, 1));
	*b = ft_calloc(*size_a, sizeof(int));
	if (*b == NULL)
		return (free_all(*a, NULL, 1, 1));
	*size_b = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	int	size_a;
	int	*tab;
	int	*tab_b;
	int	size_b;
	int	res;

	if (argc <= 1)
		return (1);
	if (argv[1][0] == '-')
		size_a = check_args(argc - 1, argv, 2);
	else
		size_a = check_args(argc, argv, 1);
	if (size_a == 0)
		return (1);
	if (init_tab(&tab, &tab_b, &size_a, &size_b) == 1)
		return (1);
	if (argv[1][0] == '-')
		res = fill_tab(tab, size_a, argv, 2);
	else
		res = fill_tab(tab, size_a, argv, 1);
	if (res == 0)
		return (free_all(tab, tab_b, 0, 1));
	res = choose_strategy(argv, tab, tab_b, size_a);
	if (res == -1)
		return (1);
	return (0);
}
