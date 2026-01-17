/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:24:27 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/16 14:59:56 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sorted(int *tab_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
/*
void	applied_rules(int nb, t_stacks *stack, t_actions *actions)
{
	if (nb == 2)
		sa(stack->tab_a, stack->size_a, actions);
	if (nb == 3)
		sb(stack->tab_b, stack->size_b, actions);
	if (nb == 4)
		ra(stack->tab_a, stack->size_a, actions);
	if (nb == 5)
		rb(stack->tab_b, stack->size_b, actions);
	if (nb == 6)
		rra(stack->tab_a, stack->size_a, actions);
	if (nb == 7)
		rrb(stack->tab_a, stack->size_a, actions);
	if (nb == 8)
		pa(stack, actions);
	if (nb == 9)
		pb(stack, actions);
	if (nb == 10)
		ss(stack, actions);
	if (nb == 11)
		rr(stack, actions);
	if (nb == 12)
		rrr(stack, actions);
}

int check_args(char *check, int size)
{
	if (ft_strncmp(check, "sa", size) == 0)
		return (2);
	else if  (ft_strncmp(check, "sb", size) == 0)
		return (3);
	else if  (ft_strncmp(check, "ra", size) == 0)
		return (4);
	else if  (ft_strncmp(check, "rb", size) == 0)
		return (5);
	else if  (ft_strncmp(check, "rra", size) == 0)
		return (6);
	else if  (ft_strncmp(check, "rrb", size) == 0)
		return (7);
	else if  (ft_strncmp(check, "pa", size) == 0)
		return (8);
	else if  (ft_strncmp(check, "pb", size) == 0)
		return (9);
	else if  (ft_strncmp(check, "ss", size) == 0)
		return (10);
	else if  (ft_strncmp(check, "rr", size) == 0)
		return (11);
	else if  (ft_strncmp(check, "rrr", size) == 0)
		return (12);
	return (0);
}

int	read_standard_input(t_stacks *stack, t_actions *actions)
{
	char	*check;
	int		nb;

	while (!(check))
	{
		check = get_next_line(0);
		size = ft_strlen_(check);
		nb = check_args(check, size);
		if (nb == 0)
		{
			write(1, "Error\n", 6);
			free(check);
			return (1);
		}
		else 
			applied_rules(nb, stack, actions);
		free(check);
	}
	return (0);
}

int	main(int argc, char **argc)
{
	t_stacks	stacks;
	int 		size;
	int			nb;
	t_actions	actions;
	

	if (argc <= 1)
		return (NULL);
	actions->nb_op = 0;
	actions->lst = NULL;
	size = check_args(argc, argv, 1);
	if (size <= 0)
		return (NULL);
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, argv, 1) == 0)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	nb = read_standard_input(stack, actions);
	if (nb == 1)
		return(free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	if (is_sorted(stack->tab_a, size) == 1)
		write(1, "OK\n", 3);
	else
	write(1, "KO\n", 3);
	return (free_all(stacks.tab_a, stacks.tab_b, 0, 0));
}*/