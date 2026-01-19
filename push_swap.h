/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:24:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 10:31:09 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

//0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr
typedef struct s_actions
{
	int	nb_op;
	int	pa;
	int	sa;
	int	ra;
	int	rra;
	int	pb;
	int	sb;
	int	rb;
	int	rrb;
	int	ss;
	int	rr;
	int	rrr;
}	t_actions;

typedef struct s_stacks
{
	int	*tab_a;
	int	*tab_b;
	int	size_a;
	int	size_b;
}	t_stacks;

// 0 adaptive, 1 simple, 2 medium, 3 complex
typedef struct s_options
{
	int	strategy;
	int	display;
}	t_options;

int		sa(int *a, int size_a, t_actions *actions, int silent);
int		pa(t_stacks *stack, t_actions *actions, int silent);
int		ra(int *a, int size_a, t_actions *actions, int silent);
int		rra(int *a, int size_a, t_actions *actions, int silent);
int		sb(int *b, int size_b, t_actions *actions, int silent);
int		pb(t_stacks *stack, t_actions *actions, int silent);
int		rb(int *b, int size_b, t_actions *actions, int silent);
int		rrb(int *b, int size_b, t_actions *actions, int silent);
int		ss(t_stacks *stack, t_actions *actions, int silent);
int		rr(t_stacks *stack, t_actions *actions, int silent);
int		rrr(t_stacks *stack, t_actions *actions, int silent);
int		check_args(char **argv);
int		choose_strategy(t_stacks *stacks, t_actions *actions, t_options *opt);
int		is_arg_number(char *str);
int		free_all(t_stacks *stack, char **str, int return_value, int error);
int		get_nb_args(char **argv, t_options *opt);
int		insertion_sort(t_stacks *stack, t_actions *actions, int silent);
int		adaptive(float disorder);
int		execute_algo(int algo, t_stacks *stack, t_actions *actions);
int		is_sorted(int *tab_a, int size);
float	disorder(int *tab_a, int size);
void	display_bench(float disorder, int strat, t_actions *a, int algo);
void	init_struct_action(t_actions *actions, t_options *opt);
int		init_tab(t_stacks *stacks, int max_size);
int		fill_tab(int *tab, char **str);
char	**parse_args(int argc, char **argv, int start);
void	free_split(char **split);
int		is_arg_number(char *str);

#endif