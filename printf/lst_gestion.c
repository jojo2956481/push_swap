/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:14:24 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/17 10:14:25 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*create_lst(char type, char *sup_arg, t_printf *lst, int place)
{
	t_printf	*new_node;

	new_node = lst_new(type, sup_arg, place);
	if (!new_node)
		return (NULL);
	if (!lst)
		return (new_node);
	lst_add_back(lst, new_node);
	return (lst);
}
