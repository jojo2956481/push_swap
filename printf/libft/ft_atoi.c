/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:24:35 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:25:45 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (nptr[i++] - '0');
	return (nb * sign);
}
/*
#include <stdlib.h>

int main(void)
{
	printf("ft_atoi : %d\n", ft_atoi("-21474836448"));
	printf("atoi    : %d\n", atoi("-21474836448"));
	printf("ft_atoi : %d\n", ft_atoi("   +42"));
	printf("atoi    : %d\n", atoi("   +42"));
	printf("ft_atoi : %d\n", ft_atoi("9999999999"));
	printf("atoi    : %d\n", atoi("9999999999"));
	printf("ft_atoi : %d\n", ft_atoi("-2147483648"));
	printf("atoi    : %d\n", atoi("-2147483648"));
}
 MAYBEEEEEEEEE :

 if (num * sign > 2147483647)
		   return (2147483647);
	   if (num * sign < -2147483648)
		   return (-2147483648);

 */
