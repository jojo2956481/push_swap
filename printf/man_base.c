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

static int	ft_numlen(unsigned int n, int base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	char			*hex;
	int				len;
	unsigned int	num;
	int				base_len;

	num = n;
	base_len = ft_strlen(base);
	len = ft_numlen(n, base_len);
	hex = malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	if (num < 0)
	{
		hex[0] = '-';
		num = -num;
	}
	if (num == 0)
		hex[0] = '0';
	while (num > 0)
	{
		hex[--len] = base[(num % base_len)];
		num /= base_len;
	}
	return (hex);
}
