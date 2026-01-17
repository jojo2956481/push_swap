/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:41:05 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 09:27:40 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "chunk_sort.h"
#include "libft.h"

static int	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	copy_tab(int *tab_a, int *tab_sort, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab_sort[i] = tab_a[i];
		i++;
	}
	return (0);
}

static int	fill_tab_chunk(int **tab_chunk, int *tab_sort,
		int chunk_size, int chunk_len)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (j < chunk_len)
	{
		i = 0;
		while (i < chunk_size)
		{
			tab_chunk[j][i] = tab_sort[k];
			i++;
			k++;
		}
		j++;
	}
	return (0);
}

int	**take_index(int *tab_a, int size_a, int chunk_size, int chunk_len)
{
	int	*tab_sort;
	int	i;
	int	**tab_chunk;

	i = -1;
	tab_sort = ft_calloc(size_a, sizeof(int));
	if (!tab_sort)
		return (NULL);
	tab_chunk = ft_calloc(chunk_len + 1, sizeof(int *));
	if (!tab_chunk)
		return (free_take_index(tab_sort, NULL, NULL));
	while (++i < chunk_len)
	{
		tab_chunk[i] = ft_calloc(chunk_size, sizeof(int));
		if (!tab_chunk[i])
			return (free_take_index(tab_sort, NULL, tab_chunk));
	}
	copy_tab(tab_a, tab_sort, size_a);
	sort_tab(tab_sort, size_a);
	fill_tab_chunk(tab_chunk, tab_sort, chunk_size, chunk_len);
	free(tab_sort);
	return (tab_chunk);
}

int	isqrt(int n)
{
	int	x;

	x = 0;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x);
}
