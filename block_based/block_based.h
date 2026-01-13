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

#include <push_swap.h>

void	sort_by_blocks(int *tab_a, int *size_a);
int		*block_sort_cpy(int *tab_a, int	*tab_b, int *size_a, int *size_b);
int		block_sort(t_stacks *stack, t_actions *actions);
int		*block_sort_without_rules(int *tab_a, int size_a);
void	init_min_heap_cpy(int *tab, int size_tab, int *min_heap);
int		*init_pos_cpy(int nb_block);
void	bubble_sort_cpy(int *tab, int n);
int		ft_sqrt(int n);

#endif
