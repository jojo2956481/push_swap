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

typedef struct s_actions
{
	int nb_op;
	int pa;
	int sa;
	int ra;
	int rra;
	int pb;
	int sb;
	int rb;
	int rrb;
	int	ss;
	int	rr;
	int rrr;
}	t_actions;

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
int		check_args(int argc, char **argv, int start);
int		choose_strategy(char **argv, int *tab_a, int *tab_b, int size_a);
int		is_arg_number(char *str);
int		free_all(int *a, int *b, int return_value, int error);

#endif