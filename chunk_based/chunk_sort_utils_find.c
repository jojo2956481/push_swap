/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils_find.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:47:36 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:20:34 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "chunk_sort.h"

int	find_index(int *shunk, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (shunk[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_max_value(int *tab_b, int size_b)
{
	int	i;
	int	max;

	i = 0;
	max = tab_b[0];
	while (i < size_b)
	{
		if (tab_b[i] > max)
			max = tab_b[i];
		i++;
	}
	return (max);
}

int	**free_take_index(int *a, int *b, int **tab)
{
	int	i;

	if (a)
		free(a);
	if (b)
		free(b);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}
