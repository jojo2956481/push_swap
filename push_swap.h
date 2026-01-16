/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:24:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/16 13:14:09 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

//0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr
typedef struct s_order
{
	int				action;
	struct s_order	*next;
}	t_order;

typedef struct s_actions
{
	int		nb_op;
	t_order	*lst;
}	t_actions;

typedef struct s_stacks
{
	int	*tab_a;
	int	*tab_b;
	int	size_a;
	int	size_b;
}	t_stacks;

// 0 none, 1 simple, 2 medium, 3 complex, 4 adaptive
typedef struct s_options
{
	int	strategy;
	int	display;
}	t_options;

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
int		choose_strategy(t_stacks *stacks, t_actions *actions, t_options *opt);
int		is_arg_number(char *str);
int		free_all(int *a, int *b, int return_value, int error);
int		get_nb_args(char **argv, t_options *opt);
t_order	*ft_lstcreate(int content);
t_order	*ft_lst_get_last(t_order *lst);
void	ft_lst_add_back(t_order **lst, t_order *new);
int		get_action(t_order *lst, int type);
void	ft_lstdelete(t_order **lst);
int		insertion_sort(t_stacks *stack, t_actions *actions);
int		chunk_sort(t_stacks *stack, t_actions *actions);
int		radix(t_stacks *stack, t_actions *actions);
int		is_sorted(int *tab_a, int size);
float	disorder(int *tab_a, int size);

#endif