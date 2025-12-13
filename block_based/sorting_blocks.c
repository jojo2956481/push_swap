/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 08:57:31 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/13 08:57:32 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sort_three_cases(int *tab)
{
	int	count;

	count = 0;
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
	return (count);
}

static int	sort_three(int *tab, int to_low)
{
	int	count;

	count = 0;
	if (to_low == 1)
		return (0);
	if (to_low == 2)
	{
		if (tab[0] > tab[1])
			sa(tab, 3);
		return (1);
	}
	if (tab[0] < tab[1] && tab[1] < tab[2])
		return (0);
	count += sort_three_cases(tab);
	return (count);
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
