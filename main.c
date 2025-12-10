/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:23:30 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/09 16:36:34 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>
/* debut du parsing : formate l'input
(./pusg_swap 12 846 84 24 12 en tab = {12, 846, 84, 24, 12}).
check si l'input est un int et si c'est un digit.
je check pas encore les doublons.*/

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
	int	i;

	if (argc <= 1)
		return (0);
	size = ft_checkdigit(argv, (argc - 1));
	if (size == 0)
		return (0);
	tab = ft_calloc(size, sizeof(int));
	fill_tab(tab, size, argv);
	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
