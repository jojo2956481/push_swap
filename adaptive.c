/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:24:51 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/20 09:14:34 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "chunk_sort.h"
#include "radix.h"

int	adaptive(float disorder)
{
	if (disorder < 0.2)
		return (1);
	if (disorder >= 0.2 && disorder < 0.5)
		return (2);
	if (disorder >= 0.5)
		return (3);
	return (-1);
}

int	execute_algo(int algo, t_stacks *stack, t_actions *actions)
{
	if (algo == 1)
		return (selection_sort(stack, actions, 0));
	if (algo == 2)
		return (chunk_sort(stack, actions, 0));
	if (algo == 3)
		return (radix(stack, actions, 0));
	return (-1);
}
