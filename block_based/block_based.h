/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_based.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:12:56 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/13 09:13:00 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_BASED_H
# define BLOCK_BASED_H

# include <push_swap.h>

int	block_sort(t_stacks *stack, t_actions *actions);
int	*block_sort_without_rules(int *tab_a, int size_a);

#endif
