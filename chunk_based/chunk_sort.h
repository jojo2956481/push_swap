/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:48:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 09:28:45 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_SORT_H
# define CHUNK_SORT_H

# include "push_swap.h"

int	find_index(int *shunk, int size, int value);
int	find_max_value(int *tab_b, int size_b);
int	**take_index(int *tab_a, int size_a, int chunk_size, int chunk_len);
int	isqrt(int n);
int	**free_take_index(int *a, int *b, int **tab);
int	chunk_sort(t_stacks *stack, t_actions *actions, int silent);

#endif