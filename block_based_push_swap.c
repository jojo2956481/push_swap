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

#include "push_swap.h"
//here, pb seulement multiple de 3
//here, pb seulement multiple de 3
//here, pb seulement multiple de 3
//here, pb seulement multiple de 3
//here, pb seulement multiple de 3
//here, pb seulement multiple de 3

int sort_three(int *tab, int to_low)
{
	int count = 0;

	if (to_low == 1)
		return (0);
	if (to_low == 2)
	{
		if (tab[0] > tab[1])
			sa(tab, 3);
		return (1);
	}
	if (tab[0] < tab[1] && tab[1] < tab[2])
		return 0;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		count += sa(tab, 3);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		count += ra(tab, 3);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		count += sa(tab, 3);
		count += ra(tab, 3);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		count += rra(tab, 3);
	else if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		count += sa(tab, 3);
		count += rra(tab, 3);
	}
	return count;
}

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

void	sort_by_blocks(int *tab_a, int *size_a)
{
	int	i;
	int	n;

	i = 0;
	while (*size_a > i)
	{
		n = 3;
		if (*size_a - i < 3)
			n = *size_a - i;
		sort_three(tab_a, n);
		while (n > 0)
		{
			ra(tab_a, *size_a);
			n--;
		}
		i += 3;
	}
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


#include <stdio.h>
int main(void)
{
	int tab_a[18] = {15, 11, 8, 2, 1, 14, 13, 18, 5, 7, 17, 9, 4, 3, 10, 6, 16, 12};
	int tab_b[18] = {};
	int size_a = 18;
	int size_b = 0;
	int i = 0;

	block_sort(tab_a, tab_b, &size_a, &size_b);

	//printf("|-----------------|\n");
	//printf("|      tab_a      |\n");
	//printf("|-----------------|\n");
//
	//while (i < size_a)
	//{
	//	printf("|% 6d    |\n", tab_a[i]);
	//	i++;
	//}
	return 0;
}
