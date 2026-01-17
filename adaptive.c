/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:24:51 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/17 09:24:58 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "chunk_sort.h"
#include "radix.h"
#include "libft.h"

int	get_actions(int (*f)(t_stacks*, t_actions*), t_stacks stack, t_actions a)
{
	int	*temp_tab;
	int	err;

	temp_tab = malloc(sizeof(int) * stack.size_a);
	if (!temp_tab)
		return (-1);
	ft_memcpy(temp_tab, stack.tab_a, stack.size_a);
	stack.tab_a = temp_tab;
	err = f(&stack, &a);
	free(temp_tab);
	if (err == -1)
		return (-1);
	return (a.nb_op);
}

int	adaptive(t_stacks stack)
{
	int			chunk;
	int			radix_val;
	int			insertion;
	t_actions	a;

	a.nb_op = 0;
	chunk = get_actions(chunk_sort, stack, a);
	radix_val = get_actions(radix, stack, a);
	insertion = get_actions(insertion_sort, stack, a);
	if (insertion == 1 || radix_val == 1 || chunk == 1)
		return (-1);
	if (chunk < radix_val && chunk < insertion)
		return (2);
	else if (radix_val < insertion)
		return (3);
	return (1);
}

int	execute_algo(int algo, t_stacks *stack, t_actions *actions)
{
	if (algo == 1)
		return (insertion_sort(stack, actions));
	if (algo == 2)
		return (chunk_sort(stack, actions));
	if (algo == 3)
		return (radix(stack, actions));
	return (-1);
}
