/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:01:25 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/08 12:42:48 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_intlen_u(unsigned int n)
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

int	ft_putnbr_unsigned(unsigned int n)
{
	if (n == 2147483648)
	{
		write(1, "2147483648", 10);
		return (10);
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_unsigned((n / 10));
		ft_putchar((n % 10) + '0');
	}
	return (ft_intlen_u(n));
}
