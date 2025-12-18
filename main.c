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

#include "./printf/libft/libft.h"
#include "./printf/src/ft_printf.h"
#include "./block_based/block_based.h"
#include <limits.h>
#include <stdlib.h>
/* debut du parsing : formate l'input
(./pusg_swap 12 846 84 24 12 en tab = {12, 846, 84, 24, 12}).
check si l'input est un int et si c'est un digit.
je check pas encore les doublons.*/


int	check_same(int *tab, int size)
{
	int	i;
	int	j;

    i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] == tab[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


// check digit
int	ft_checkdigit(char **str, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i <= size)
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
			{
				return (0);
				ft_printf("%s\n", "Error");
			}
			j++;
		}
		i++;
	}
	return (size);
}

// remplie le tableau d'int
int	fill_tab(int *tab, int size_tab, char **str)
{
	int	i;
	int	j;
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
	size = ft_checkdigit(argv, (argc - 1));
	if (size == 0)
	{
		ft_printf("%s\n", "Error");
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
	if (check_same(tab, size) == 0)
	{
		free(tab);
		ft_printf("%s\n", "Error");
		return (1);
	}
	block_sort(tab, tab_b, &size, &size_b);
	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
	free(tab_b);
	free(tab);
	return (0);
}
