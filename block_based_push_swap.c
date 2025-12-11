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

void	sorting_blocks(int size_tab, int *tab)
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

void push_block_to_b(int *a, int *b, int *size_a, int *size_b)
{
	int	n;

	n = 0;
	while (n < 3)
	{
		pb(a, b, size_a, size_b);
		n++;
	}
}

int	*block_sort(int *tab_a, int *size_a)
{
	int	nb_block;
	int *tab_b;
	int size_b;

	size_b = 0;
	tab_b = calloc(*size_a, sizeof(int));
	if (!tab_b)
		return (NULL);
	nb_block = *size_a / 3;
	if (*size_a % 3 != 0)
		nb_block++;
	sorting_blocks(*size_a, tab_a);
	print(tab_a, tab_b);
	int	i;
	i = 0;
	while (i < nb_block)
	{
		push_block_to_b(tab_a, tab_b, size_a, &size_b);
		i++;
	}
	print(tab_a, tab_b);
	rrb(tab_b, size_b);
	pa(tab_a, tab_b, size_a, &size_b);
	return (tab_b);
}


#include <stdio.h>
int main(void)
{
	int tab_a[10] = {5, 9, 1, 7, 3, 5, 5, 8, 1};
	int size_a = 9;
	int	*tab_b = block_sort(tab_a, &size_a);
	print(tab_a, tab_b);
	free(tab_b);
	return 0;
}
