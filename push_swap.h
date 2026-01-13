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

typedef struct s_stacks
{
	int	*tab_a;
	int	*tab_b;
	int size_a;
	int size_b;
}	t_stacks;

int		sa(int *a, int size_a, t_actions *actions);
int		pa(t_stacks *stack, t_actions *actions);
int		ra(int *a, int size_a, t_actions *actions);
int		rra(int *a, int size_a, t_actions *actions);
int		sb(int *b, int size_b, t_actions *actions);
int		pb(t_stacks *stack, t_actions *actions);
int		rb(int *b, int size_b, t_actions *actions);
int		rrb(int *b, int size_b, t_actions *actions);
int		ss(t_stacks *stack, t_actions *actions);
int		rr(t_stacks *stack, t_actions *actions);
int		rrr(t_stacks *stack, t_actions *actions);
int		check_args(int argc, char **argv, int start);
int		choose_strategy(char **argv, t_stacks *stacks, t_actions *actions);
int		is_arg_number(char *str);
int		free_all(int *a, int *b, int return_value, int error);

#endif