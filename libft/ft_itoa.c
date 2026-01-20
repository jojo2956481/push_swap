/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:49:19 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:46:16 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nb;

	nb = n;
	size = intlen(nb);
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (0);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (size > 0 && str[size -1] != '-')
	{
		str[--size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
