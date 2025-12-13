/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_based.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:11:09 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/11 08:11:11 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(int *tab, int size_tab, int *idx_min)
{
	int	i;
	int	min;
	int	idx;

	min = tab[idx_min[0]];
	i = 0;
	idx = i;
	while (i < size_tab)
	{
		if (tab[idx_min[i]] < min)
		{
			min = tab[idx_min[i]];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	init_utils(int **idx_min, int *size_a)
{
	int	i;
	int	nb_block;

	i = 0;
	nb_block = *size_a / 3;
	if (*size_a % 3 != 0)
		nb_block++;
	*idx_min = malloc(sizeof(int) * nb_block);
	if (!*idx_min)
		return (0);
	while (i < nb_block)
	{
		(*idx_min)[i] = i * 3;
		i++;
	}
	return (nb_block);
}

int	go_to_idx(int *tab_a, int *idx_min, int *size_a, int nb_block)
{
	int	min;
	int	i;

	min = find_min(tab_a, nb_block, idx_min);
	i = 0;
	while (i < idx_min[min])
	{
		ra(tab_a, *size_a);
		i++;
	}
	while (++min < nb_block)
		idx_min[min] = idx_min[min] - 1;
	return (i);
}

int	*block_sort(int *tab_a, int	*tab_b, int *size_a, int *size_b)
{
	int	nb_block;
	int	i;
	int	*idx_min;

	idx_min = NULL;
	nb_block = init_utils(&idx_min, size_a);
	if (nb_block == 0)
		return (NULL);
	sort_by_blocks(tab_a, size_a);
	while (*size_a != 0)
	{
		i = go_to_idx(tab_a, idx_min, size_a, nb_block);
		pb(tab_a, tab_b, size_a, size_b);
		while (i-- > 0)
			rra(tab_a, *size_a);
	}
	while (*size_b != 0)
		pa(tab_a, tab_b, size_a, size_b);
	free(idx_min);
	return (tab_a);
}

/*
#include <stdio.h>
int main(void)
{
	int tab_a[30] = {12, 14, 30, 21, 1, 7, 29,
2 ,22 ,18, 11 ,24, 28, 10 ,19 ,16, 25, 15, 8
 ,27, 13, 3, 4, 17, 20, 26, 9, 5, 6, 23 };
	int tab_b[30] = {};
	int size_a = 30;
	int size_b = 0;
	int i = 0;

	block_sort(tab_a, tab_b, &size_a, &size_b);

	printf("|-----------------|\n");
	printf("|      tab_a      |\n");
	printf("|-----------------|\n");

	while (i < size_a)
	{
		printf("|% 6d    |\n", tab_a[i]);
		i++;
	}
	return 0;
}
*/