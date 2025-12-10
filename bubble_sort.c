/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:16:58 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 12:29:30 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int k;
	int count;

	j = 0;
	count = 0;
	while (j < size -1)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			k = 0;
			while (k < i)
			{
				count += ra(tab, size);
				k++;
			}
			if (tab[0] > tab[1])
				count += sa(tab, size);
			k = 0;
			while (k < size - i)
			{
				count += ra(tab, size);
				k++;
			}
			i++;
		}
		j++;
	}
	return (count);
}
