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
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];
	if (to_low == 1)
		return (0);
	if (to_low == 2)
	{
		if (a < b)
			sa(tab, 3);
		return (1);
	}
	if (a < b && b < c)
		return 0;
	if (a > b && b < c && a < c)
		return count + sa(tab, 3);
	if (a < b && b > c && a > c)
	{
		count += rra(tab, 3);
		count += sa(tab, 3);
		return count;
	}
	if (a > b && b > c)
	{
		count += sa(tab, 3);
		count += rra(tab, 3);
		return count;
	}
	if (a > c && c > b)
		return count + ra(tab, 3);
	if (b > a && a > c)
		return count + rra(tab, 3);

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

	i = 0;
	while (*size_a > i)
	{
		sort_three(tab_a, *size_a - i);
		ra(tab_a, *size_a);
		ra(tab_a, *size_a);
		ra(tab_a, *size_a);
		i += 3;
	}
}

int	go_to_idx(int *tab_a, int *idx_min, int *size_a, int nb_block)
{
	int	min;
	int	i;

	min = find_min(tab_a, 3, idx_min);
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

void	print(int *tab_a, int *tab_b)
{
	int i;
	i = 0;
	__builtin_printf("|-----------------|\n");
	__builtin_printf("| idx     tab_a |\n");
	__builtin_printf("|-----------------|\n");
	while (i < 11)
	{
		__builtin_printf("|% 4d   ||% 4d   |\n", tab_a[i], tab_b[i]);
		i++;
	}
	__builtin_printf("\n\n\n");
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
	print(tab_a, tab_b);
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
	int tab_a[12] = {10,9,6,  4,8,5,  1,2,3,  3};
	int tab_b[12] = {};
	int size_a = 10;
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
