/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:03:36 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 10:01:21 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_base_p(unsigned long n, int swbase)
{
	unsigned long	base_len;

	base_len = ft_strlen_p(base(swbase));
	if (n >= base_len)
	{
		ft_putnbr_base_p((n / base_len), swbase);
	}
	write(1, &base(swbase)[n % base_len], 1);
	return (ft_intlen_base(n));
}

int	ft_putptr(unsigned long ptr)
{
	int	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	n = ft_putnbr_base_p(ptr, 1);
	return (n + 2);
}
