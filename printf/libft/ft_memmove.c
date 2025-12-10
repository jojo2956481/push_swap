/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:28:03 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:28:04 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
/*
#include "stdio.h"
#include <string.h>

int	main(void)
{
	char b[5];
	char str[8] = "echoech";
	ft_memmove(b, str, 4);
	printf("%s\n", b);
}*/