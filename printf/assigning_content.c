/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:11:18 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/21 09:11:23 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*handle_strings(t_printf *lst, va_list args)
{
	void	*tmp;

	if (lst->type == 's')
	{
		tmp = va_arg(args, char *);
		if (tmp)
			return (ft_strdup(tmp));
		else
			return (ft_strdup("(null)"));
	}
	if (lst->type == 'd' || lst->type == 'i')
		return (ft_itoa_base_int(va_arg(args, int), "0123456789"));
	if (lst->type == 'u')
		return (ft_itoa_u(va_arg(args, int)));
	if (lst->type == 'x')
		return (ft_itoa_base(va_arg(args, int), "0123456789abcdef"));
	if (lst->type == 'X')
		return (ft_itoa_base(va_arg(args, int), "0123456789ABCDEF"));
	if (lst->type == 'p')
		return (base_p(va_arg(args, void *)));
	return (NULL);
}

static int	handle_mix(t_printf *lst, va_list args)
{
	if (lst->type == 'c')
		return (man_c(lst, va_arg(args, int)), 0);
	if (lst->type == '%')
		return ((lst->content = ft_strdup("%")) == NULL);
	return (-1);
}

int	fill_content(t_printf *lst, va_list args)
{
	int	mix_status;

	mix_status = handle_mix(lst, args);
	if (mix_status >= 0)
		return (mix_status);
	lst->content = handle_strings(lst, args);
	if (!lst->content)
		return (1);
	return (0);
}
