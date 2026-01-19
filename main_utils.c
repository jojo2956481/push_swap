/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:06:26 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 10:35:00 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
