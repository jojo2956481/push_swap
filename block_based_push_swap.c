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
	__builtin_printf("| tab_a     tab_b |\n");
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

void	sorting_blocks(int *tab, int size_tab)
{
	int	i;
	int	end;

	i = 0;
	while (i < size_tab)
	{
		end = i + 3;
		if (end > size_tab)
			end = size_tab;
		bubble_sort(&tab[i], end - i);
		i += 3;
	}
}

int	find_min(int *tab, int size_tab)
{
	int	i;
	int	min;
	int	idx;

	min = tab[0];
	i = 0;
	idx = i;
	while (++i < size_tab)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			idx = i;
		}
	}
	return (idx);
}

int *block_sort(int *tab_a, int *size_a)
{
	int     nb_block;
	int    *tab_b;
	//int     size_b = 0;
	//int     idx;

	tab_b = calloc(*size_a, sizeof(int));
	if (!tab_b)
		return (NULL);
	nb_block = *size_a / 3;
	if (*size_a % 3 != 0)
		nb_block++;
	int	i;
	i = 0;
	while (nb_block > i)
	{
		bubble_sort_block(tab_a, 3);
		print(tab_a, tab_b);
		ra(tab_a, *size_a);
		ra(tab_a, *size_a);
		ra(tab_a, *size_a);

		//pb(tab_a, tab_b, size_a, &size_b);
		//pb(tab_a, tab_b, size_a, &size_b);
		//pb(tab_a, tab_b, size_a, &size_b);

		i++;
	}

	print(tab_a, tab_b);
	//idx = find_min(tab_b, size_b);
	//if (idx <= size_b / 2)
	//	while (idx-- > 0)
	//		rb(tab_b, size_b);
	//else
	//	while (idx++ < size_b)
	//		rrb(tab_b, size_b);
	//while (size_b > 0)
	//	pa(tab_a, tab_b, size_a, &size_b);
	//print(tab_a, tab_b);
	free(tab_b);
	return (tab_a);

}


#include <stdio.h>
int main(void)
{
	int tab_a[10] = {4,8,7, 3,6,2, 5,9,1};
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
