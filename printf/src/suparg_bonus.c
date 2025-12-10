/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suparg_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:52:33 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/19 08:52:38 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bon_arg_man(char **sup_arg, const char *str, int *i)
{
	int	place;
	int	len;

	len = 1;
	while (str[*i + len] == '-' || str[*i + len] == '+'
		|| str[*i + len] == '#' || str[*i + len] == '.'
		|| str[*i + len] == ' ' || (str[*i + len] >= '0'
			&& str[*i + len] <= '9'))
		len++;
	*sup_arg = ft_strndup(&str[*i], len);
	place = *i;
	*i += len;
	return (place);
}

char	bonus_type(char *sup_arg, int *size)
{
	char	c;
	int		i;

	i = 1;
	if (sup_arg && sup_arg[0])
	{
		if (is_in_tab(sup_arg[1], "-0.+ #"))
		{
			c = sup_arg[1];
			while (sup_arg[i] == c)
				i++;
			if (sup_arg[i] >= '0' && sup_arg[i] <= '9')
				*size = ft_atoi(&sup_arg[i]);
			return (c);
		}
		else if (is_in_tab(sup_arg[1], "0123456789"))
		{
			*size = ft_atoi(&sup_arg[i]);
			return ('n');
		}
	}
	return (0);
}
