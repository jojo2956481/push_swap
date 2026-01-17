/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:24:27 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/17 12:41:43 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "radix.h"
#include "libft.h"
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

void replace_end_line(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\n' && str[i] == '\0')
		i++;
	str[i] = '\0';	
}

void	applied_rules(int nb, t_stacks *stacks, t_actions *actions)
{
	if (nb == 2)
		sa(stacks->tab_a, stacks->size_a, actions);
	if (nb == 3)
		sb(stacks->tab_b, stacks->size_b, actions);
	if (nb == 4)
		ra(stacks->tab_a, stacks->size_a, actions);
	if (nb == 5)
		rb(stacks->tab_b, stacks->size_b, actions);
	if (nb == 6)
		rra(stacks->tab_a, stacks->size_a, actions);
	if (nb == 7)
		rrb(stacks->tab_a, stacks->size_a, actions);
	if (nb == 8)
		pa(stacks, actions);
	if (nb == 9)
		pb(stacks, actions);
	if (nb == 10)
		ss(stacks, actions);
	if (nb == 11)
		rr(stacks, actions);
	if (nb == 12)
		rrr(stacks, actions);
}

int check_rules(char *check, int size)
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

int	read_standard_input(t_stacks *stacks, t_actions *actions)
{
	char	*check;
	int		nb;
	int		size;

	check = "echo";
	while (check)
	{
		check = get_next_line(0);
		if (!check)
			break;
		replace_end_line(check);
		size = ft_strlen(check);
		nb = check_rules(check, size);
		if (nb == 0)
			write(1, )
		applied_rules(nb, stacks, actions);
		free(check);
	}
	return (0);
}

void	init_actions(t_actions *actions)
{
	actions->nb_op = 0;
	actions->lst = NULL;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int 		size;
	int			nb;
	t_actions	actions;
	char		**args;
	
	init_actions(&actions);
	if (argc <= 1)
		return (0);
	args = parse_args(argc, argv, 1);
	size = check_args(args);
	if (size <= 0)
		return (0);
	if (init_tab(&stacks, size) == 1)
		return (1);
	if (fill_tab(stacks.tab_a, args) == 0)
		return (free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	nb = read_standard_input(&stacks, &actions);
	if (nb == 1)
		return(free_all(stacks.tab_a, stacks.tab_b, 1, 1));
	if (is_sorted(stacks.tab_a, size) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_all(stacks.tab_a, stacks.tab_b, 0, 0));
}