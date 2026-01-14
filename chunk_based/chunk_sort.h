/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:48:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/14 15:53:06 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_SORT_H
# define CHUNK_SORT_H

int	find_max(int *tab_sort, int *tab_b, int size_b, int chunk_size);
int	find_index(int *shunk, int size, int value);
int	find_max_value(int *tab_b, int size_b);
int	sort_tab(int *tab, int size);
int	copy_tab(int *tab_a, int *tab_sort, int size);
int	fill_tab(int **tab_chunk, int *tab_sort, int chunk_size, int chunk_len);
int	**take_index(int *tab_a, int size_a, int chunk_size);
int isqrt(int n);