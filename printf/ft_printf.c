/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:19:36 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 10:02:55 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *str, ...)
{
	int		n;
	va_list	args;

	if (!str)
		return (-1);
	va_start (args, str);
	n = ft_loop(fd, (char *)str, args);
	va_end(args);
	return (n);
}
