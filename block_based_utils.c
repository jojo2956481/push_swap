/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_based_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:53:43 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/11 08:53:46 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*init_pos(int nb_block)
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

void	init_min_heap(int *tab, int size_tab, int *min_heap)
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
