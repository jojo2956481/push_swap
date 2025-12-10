/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:30:18 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/18 10:30:20 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen_p(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa_base_p(unsigned long long n, char *base)
{
	int		len;
	char	*str;

	len = ft_numlen_p(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[--len] = base[n % 16];
		n /= 16;
	}
	return (str);
}

char	*base_p(void *ptr)
{
	unsigned long long	num;
	char				*hex;
	size_t				len;
	char				*res;

	if (!ptr)
		return (ft_strdup("(nil)"));
	num = (unsigned long long)ptr;
	hex = ft_itoa_base_p(num, "0123456789abcdef");
	if (!hex)
		return (NULL);
	len = ft_strlen(hex);
	res = malloc(len + 3);
	if (!res)
		return (free(hex), NULL);
	res[0] = '0';
	res[1] = 'x';
	ft_memcpy(res + 2, hex, len + 1);
	free(hex);
	return (res);
}
