/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:34:00 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/19 08:34:05 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	man_c(t_printf *lst, int arg)
{
	char	c;

	if (lst->type == 'c')
		c = (char)arg;
	lst->content = malloc(2);
	if (!lst->content)
		return ;
	((char *)lst->content)[0] = c;
	((char *)lst->content)[1] = '\0';
}
