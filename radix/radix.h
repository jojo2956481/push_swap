/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:59:48 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 10:05:14 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_H
# define RADIX_H

# include <push_swap.h>

void	sort_tab(int *tab, int size);
void	copy_tab_radix(int *tab_a, int *tab_sort, int size);
void	indexation(int *tab_sort, int *tab, int *tab_index, int size);
int		init_bit_max(int *tab_sort, int size);
int		radix(t_stacks *stack, t_actions *actions);

#endif