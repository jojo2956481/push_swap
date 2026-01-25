/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:06:26 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/25 10:45:44 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	free_all(t_stacks *stack, char **str, int return_value, int error)
{
	if (stack)
	{
		if (stack->tab_a)
			free(stack->tab_a);
		if (stack->tab_b)
			free(stack->tab_b);
	}
	if (str)
		free_split(str);
	if (error)
		write(2, "Error\n", 6);
	return (return_value);
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (-1);
		while (ft_isdigit(s[i]))
			i++;
		while (s[i] == ' ' || s[i] == '\t')
			i++;
	}
	return (0);
}

int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
