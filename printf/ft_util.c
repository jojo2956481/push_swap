/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:12:45 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 10:01:01 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen_p(const char *str)
{
	long int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*base(int swbase)
{
	char	*base1;
	char	*base2;

	if (swbase == 1)
	{
		base1 = "0123456789abcdef";
		return (base1);
	}
	else
	{
		base2 = "0123456789ABCDEF";
		return (base2);
	}
}

int	ft_intlen_base(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
