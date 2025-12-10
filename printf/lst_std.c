/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:41:53 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/17 08:42:02 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*lst_new(char type, char *sup_args, int place)
{
	t_printf	*new;

	new = malloc(sizeof(t_printf));
	if (!new)
		return (NULL);
	new->type = type;
	new->place = place;
	new->sup_args = ft_strdup(sup_args);
	if (!new->sup_args)
		return (NULL);
	new->next = NULL;
	new->content = NULL;
	return (new);
}

void	lst_add_back(t_printf *lst, t_printf *new)
{
	t_printf	*last;

	if (!lst || !new)
		return ;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	last = lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	free_lst(t_printf *lst)
{
	t_printf	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst->sup_args);
		free(lst);
		lst = tmp;
	}
}

static int	apply_bonus(t_printf *lst, char type, int size, char *str)
{
	if (type == '0' && is_in_tab(lst->type, "diuxX"))
		return (print_bonus_zero(lst, size, str));
	if (type == '-' && is_in_tab(lst->type, "cspdiuxX"))
		return (print_bonus_dash(lst, size, str));
	if (type == '.' && lst->type == 's')
		return (print_bonus_point(size, str));
	if (type == '.' && is_in_tab(lst->type, "cpdiuxX"))
		return (print_bonus_zero(lst, size, str));
	if (type == 'n' && is_in_tab(lst->type, "cspdiuxX"))
		return (print_bonus_front_spaces(lst, size, str));
	if (type == '+' && is_in_tab(lst->type, "di"))
		return (print_bonus_plus(lst, str));
	if (type == ' ' && is_in_tab(lst->type, "di"))
		return (print_bonus_space(str));
	if (type == '#' && is_in_tab(lst->type, "xX"))
		return (print_bonus_hash(lst, str));
	return (print_content(str, lst->type));
}

t_printf	*lst_print(t_printf *lst, int *i, int *count)
{
	char	*str;
	char	type;
	int		size;

	str = (char *)lst->content;
	size = 0;
	type = bonus_type(lst->sup_args, &size);
	size = apply_bonus(lst, type, size, str);
	*count += size;
	if (lst->type == '%')
		*i += ft_strlen(lst->content) + ft_strlen(lst->sup_args) + 1;
	else
		*i += ft_strlen(lst->sup_args) + 1;
	return (lst->next);
}
