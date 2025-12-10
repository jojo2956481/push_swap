/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:07:27 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/18 11:07:30 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_in_tab(char c, char *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (c == tab[i])
			return (1);
		i++;
	}
	return (0);
}

static t_printf	*create_percent_lst(t_printf *lst, int place)
{
	char	*arg_percent;

	arg_percent = ft_strdup("");
	lst = create_lst('%', arg_percent, lst, place);
	free(arg_percent);
	return (lst);
}

static t_printf	*process_arg(t_printf *lst, const char *str, int *i)
{
	char	*sup_arg;
	int		place;

	sup_arg = NULL;
	place = bon_arg_man(&sup_arg, str, i);
	if (!sup_arg)
		return (free_lst(lst), NULL);
	if (is_in_tab(str[*i], "cspdiuxX%"))
	{
		if (str[*i] == '%')
			lst = create_percent_lst(lst, place);
		else
			lst = create_lst(str[*i], sup_arg, lst, place);
	}
	free(sup_arg);
	return (lst);
}

t_printf	*lst_built(const char *str)
{
	t_printf	*lst;
	int			i;

	i = -1;
	lst = NULL;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			lst = process_arg(lst, str, &i);
			if (!lst)
				return (NULL);
		}
	}
	return (lst);
}
