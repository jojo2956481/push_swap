/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_copy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:53:43 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/11 08:53:46 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void bubble_sort_cpy(int *tab, int n) {
	int i, j, temp;
	int swapped;

	for (i = 0; i < n - 1; i++) {
		swapped = 0;
		for (j = 0; j < n - i - 1; j++) {
			if (tab[j] > tab[j + 1]) {
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}

int	*init_pos_cpy(int nb_block)
{
	int	*pos;
	int	i;

	i = 0;
	pos = malloc(sizeof(int) * nb_block);
	if (!pos)
		return (NULL);
	while (i < nb_block)
		pos[i++] = 0;
	return (pos);
}

void	init_min_heap_cpy(int *tab, int size_tab, int *min_heap)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size_tab)
	{
		min_heap[j++] = tab[i];
		i += 3;
	}
}

