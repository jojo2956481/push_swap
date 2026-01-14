/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:43:53 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/14 08:43:57 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	bubble_sort_cpy(int *tab, int n)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = 0;
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

static void	sorting_blocks_cpy(int size_tab, int *tab)
{
	int	i;
	int	end;

	i = 0;
	while (i < size_tab)
	{
		end = i + 3;
		if (end > size_tab)
			end = size_tab;
		bubble_sort_cpy(&tab[i], end - i);
		i += 3;
	}
}

int	*block_sort_without_rules(int *cpy_tab, int size_tab)
{
	int	*tab_output;
	int	nb_block;
	int	i;

	i = 0;
	nb_block = size_tab / 3;
	if (size_tab % 3 != 0)
		nb_block++;
	tab_output = malloc(sizeof(int) * size_tab);
	if (!tab_output)
		return (NULL);
	sorting_blocks_cpy(size_tab, cpy_tab);
	while (i < size_tab)
	{
		tab_output[i] = cpy_tab[i];
		i++;
	}
	return (tab_output);
}
