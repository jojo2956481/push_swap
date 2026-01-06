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
#include "ft_printf.h"
#include "block_based.h"
#include <limits.h>
#include <stdlib.h>
/* debut du parsing : formate l'input
(./pusg_swap 12 846 84 24 12 en tab = {12, 846, 84, 24, 12}).
check si l'input est un int et si c'est un digit.
je check pas encore les doublons.*/

static int  check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j <= argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	fill_tab(int *tab, int size_tab, char **str)
{
	int	i;
	int	x;

	x = 0;
	i = 1;
	while (x < size_tab)
	{
		tab[x] = ft_atoi(str[i]);
		if (ft_atoi(str[i]) < INT_MIN || ft_atoi(str[i]) > INT_MAX)
		{
			free(tab);
			ft_printf("%s\n", "Error");
			return (0);
		}
		x++;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*tab;
	int	*tab_b;
	int	size_b;
	int	i;

	if (argc <= 1)
		return (1);
	size = check_args(argc - 1, argv);
	if (size == 0)
	{
		ft_printf("%s\n", "Error"); // PASSER UN ARGUMENT POUR CHANGER DE SORTI
		return (1);
	}
	tab = ft_calloc(size, sizeof(int));
	if (tab == NULL)
		return (1);
	tab_b = ft_calloc(size, sizeof(int));
	if (tab_b == NULL)
	{
		free(tab);
		return (1);
	}
	size_b = 0;
	fill_tab(tab, size, argv);
	block_sort(tab, tab_b, &size, &size_b);
	i = 0;/*
	while (i < size)
		ft_printf("%d\n", tab[i++]);*/
	free(tab_b);
	free(tab);
	return (0);
}
