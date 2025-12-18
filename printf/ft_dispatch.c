/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:27:14 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/09 09:17:32 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_loop(char *str, va_list args)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			n += ft_dipatch(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			n++;
		}
		i++;
	}
	return (n);
}

int	ft_dipatch(char c, va_list args)
{
	int	n;

	if (c == 'c')
		n = ft_putchar((int)va_arg(args, int));
	if (c == 's')
		n = ft_putstr((char *)va_arg(args, char *));
	if (c == 'p')
		n = ft_putptr((unsigned long)va_arg(args, unsigned long));
	if (c == 'i' || c == 'd')
		n = ft_putnbr((int)va_arg(args, int));
	if (c == 'u')
		n = ft_putnbr_unsigned((unsigned int)va_arg(args, unsigned int));
	if (c == 'x')
		n = ft_putnbr_base((unsigned int)va_arg(args, unsigned int), 1);
	if (c == 'X')
		n = ft_putnbr_base((unsigned int)va_arg(args, unsigned int), 0);
	if (c == '%')
	{
		write(1, "%", 1);
		n = 1;
	}
	return (n);
}
