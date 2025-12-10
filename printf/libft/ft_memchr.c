/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:27:29 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:27:33 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (const unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = ft_memchr("hello", 'l', 5);
	printf("%s", str);
}
*/