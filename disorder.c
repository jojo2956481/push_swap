/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:39:23 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 13:13:49 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

float	disorder(int *tab_a, int size)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size -1)
		{
			total_pairs++;
			if (tab_a[i] > tab_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
