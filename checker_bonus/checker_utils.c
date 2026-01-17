/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:44:52 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/17 14:55:26 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "radix.h"
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

void	replace_end_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' || str[i] == '\0')
		i++;
	str[i] = '\0';
}

void	applied_rules(int nb, t_stacks *stacks, t_actions *actions)
{
	if (nb == 2)
		sa(stacks->tab_a, stacks->size_a, actions, 1);
	if (nb == 3)
		sb(stacks->tab_b, stacks->size_b, actions, 1);
	if (nb == 4)
		ra(stacks->tab_a, stacks->size_a, actions, 1);
	if (nb == 5)
		rb(stacks->tab_b, stacks->size_b, actions, 1);
	if (nb == 6)
		rra(stacks->tab_a, stacks->size_a, actions, 1);
	if (nb == 7)
		rrb(stacks->tab_a, stacks->size_a, actions, 1);
	if (nb == 8)
		pa(stacks, actions, 1);
	if (nb == 9)
		pb(stacks, actions, 1);
	if (nb == 10)
		ss(stacks, actions, 1);
	if (nb == 11)
		rr(stacks, actions, 1);
	if (nb == 12)
		rrr(stacks, actions, 1);
}

int	check_rules(char *check, int size)
{
	if (ft_strncmp(check, "sa", size) == 0)
		return (2);
	else if (ft_strncmp(check, "sb", size) == 0)
		return (3);
	else if (ft_strncmp(check, "ra", size) == 0)
		return (4);
	else if (ft_strncmp(check, "rb", size) == 0)
		return (5);
	else if (ft_strncmp(check, "rra", size) == 0)
		return (6);
	else if (ft_strncmp(check, "rrb", size) == 0)
		return (7);
	else if (ft_strncmp(check, "pa", size) == 0)
		return (8);
	else if (ft_strncmp(check, "pb", size) == 0)
		return (9);
	else if (ft_strncmp(check, "ss", size) == 0)
		return (10);
	else if (ft_strncmp(check, "rr", size) == 0)
		return (11);
	else if (ft_strncmp(check, "rrr", size) == 0)
		return (12);
	else
		return (0);
}

int	read_standard_input(t_stacks *stacks, t_actions *actions)
{
	char	*check;
	int		nb;
	int		size;
	int		ifmalloc;

	check = "echo";
	ifmalloc = 0;
	while (1)
	{
		check = get_next_line(0, &ifmalloc);
		if (ifmalloc == -1)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		if (!check)
			break ;
		replace_end_line(check);
		size = ft_strlen(check);
		if (size < 2)
		{
			free(check);
			return (-1);
		}
		nb = check_rules(check, size);
		if (nb == 0)
		{
			free(check);
			return (-1);
		}
		applied_rules(nb, stacks, actions);
		free(check);
	}
	return (0);
}
