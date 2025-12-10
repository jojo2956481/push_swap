/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:53:50 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/19 08:53:52 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_all(t_printf *lst, const char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (lst && lst->place == i)
		{
			lst = lst_print(lst, &i, &count);
			continue ;
		}
		write(1, &s[i++], 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_printf	*lst;
	t_printf	*tmp;
	int			size;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	lst = lst_built(str);
	tmp = lst;
	while (lst)
	{
		if (fill_content(lst, args))
		{
			free_lst(tmp);
			va_end(args);
			return (-1);
		}
		lst = lst->next;
	}
	va_end(args);
	size = print_all(tmp, str);
	free_lst(tmp);
	return (size);
}
