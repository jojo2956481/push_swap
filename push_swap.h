/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:24:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/09 15:22:24 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
//int	main(int argc, char **argv);

int		sa(int *a, int size_a);
int		pa(int *b, int *a, int *size_b, int *size_a);
int		ra(int *a, int size_a);
int		rra(int *a, int size_a);
int		sb(int *b, int size_b);
int		pb(int *a, int *b, int *size_a, int *size_b);
int		rb(int *b, int size_b);
int		rrb(int *b, int size_b);
int		ss(int *b, int *a, int size_a, int size_b);
int		rr(int *b, int *a, int size_b, int size_a);
int		rrr(int *b, int *a, int size_b, int size_a);
int		bubble_sort(int *tab, int size);
void	init_min_heap(int *tab, int size_tab, int *min_heap); //block based
int		*init_pos(int nb_block); //block based
void	sort_by_blocks(int *tab_a, int *size_a); //block based

#endif