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

int	bubble_sort_block(int *tab, int size)
{
	int	i;
	int	j;
	int	k;
	int	count;

	j = -1;
	count = 0;
	while (++j < size -1)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			k = 0;
			while (k++ < i)
				count += ra(tab, size);
			if (tab[0] > tab[1])
				count += sa(tab, size);
			k = 0;
			while (k++ < size - i)
				count += ra(tab, size);
			i++;
		}
	}
	return (count);
}

void	print(int *tab_a, int *tab_b)
{
	int i = 0;
	__builtin_printf("|-----------------|\n");
	__builtin_printf("| idx     tab_a |\n");
	__builtin_printf("|-----------------|\n");
	if (tab_b == NULL)
	{
		while (i < 10)
		{
			__builtin_printf("|% 4d   |\n", tab_a[i]);
			i++;
		}
		__builtin_printf("\n\n\n");
		return ;
	}
	while (i < 10)
	{
		__builtin_printf("|% 4d   || % 4d   |\n", tab_a[i], tab_b[i]);
		i++;
	}
	__builtin_printf("\n\n\n");
}

int	find_min(int *tab, int size_tab, int *idx_min)
{
	int	i;
	int	min;
	int	idx;

	min = tab[idx_min[0]];
	i = 0;
	idx = i;
	while (++i < size_tab)
	{
		if (tab[idx_min[i]] < min)
		{
			min = tab[idx_min[i]];
			idx = i;
		}
	}
	return (idx);
}

int *block_sort(int *tab_a, int *size_a)
{
	int     nb_block;
	int    *tab_b;
	int    *tab_a_cpy;
	int     size_b = 0;
	//int     idx;
	int	i;
	int	*idx_min;
	int	min = 0;

	tab_b = calloc(*size_a, sizeof(int));
	if (!tab_b)
		return (NULL);
	i = 0;
	while (i < *size_a)
	{
		tab_a_cpy[i] = tab_a[i];
		i++;
	}
	nb_block = *size_a / 3;
	if (*size_a % 3 != 0)
		nb_block++;
	i = 0;
	while (nb_block > i)
	{
		bubble_sort_block(tab_a, 3);
		ra(tab_a, *size_a);
		ra(tab_a, *size_a);
		ra(tab_a, *size_a);
		i++;
	}
	__builtin_printf("echo||||||||||||||||||||||||||||||||||||||||||||||||||||");
	print(tab_a, tab_a);

	idx_min = (int *)malloc(sizeof(int) * nb_block);
	if (!idx_min)
		return (NULL);
	i = 0;
	while (i < nb_block)
	{
		idx_min[i] = i*3;
		i++;
	}
	__builtin_printf("HERE||||||||||||||||||||||||||||||||||||||||||||||||||||");
	print(idx_min, tab_a);
	while (*size_a != 0)
	{
		min = find_min(tab_a, 3, idx_min);
		i = 0;
		while (i < idx_min[min])
		{
			ra(tab_a, *size_a);
			i++;
		}
		while (++min < nb_block)
		{
			idx_min[min] = idx_min[min]-1;
		}
		pb(tab_a, tab_b, size_a, &size_b);
		while (i > 0)
		{
			rra(tab_a, *size_a);
			i--;
		}
		__builtin_printf("HERE||||||||||||||||||||||||||||||||||||||||||||||||||||");
		print(idx_min, tab_a);
	}

	print(tab_a, tab_b);
	while (size_b != 0)
	{
		pa(tab_a, tab_b, size_a, &size_b);
	}
	print(tab_a, tab_b);
	free(tab_b);
	free(idx_min);
	return (tab_a);
}


#include <stdio.h>
int main(void)
{
	int tab_a[10] = {4,8,7, 3,6,1, 5,9,2};
	int size_a = 9;
	block_sort(tab_a, &size_a);
	//int i = 0;
	//__builtin_printf("|-----------------|\n");
	//__builtin_printf("| tab_a     tab_b |\n");
	//__builtin_printf("|-----------------|\n");
	//while (i < size_a)
	//{
	//	__builtin_printf("|% 4d   || % 4d   |\n", tab_a[i], tab_b[i]);
	//	i++;
	//}
	//__builtin_printf("\n\n\n");
	//free(tab_b);
	return 0;
}
