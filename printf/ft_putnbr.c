/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:55:05 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 10:03:18 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_intlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	sign;

	sign = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		sign = 1;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr((n / 10));
		ft_putchar((n % 10) + '0');
	}
	return (ft_intlen(n) + sign);
}
