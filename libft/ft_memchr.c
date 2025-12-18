/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:28:53 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 08:50:09 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	*str = "fblknlkfgh";
	char	c;
	c = '\0';

	printf("%s", (char *)ft_memchr(str, c, 10));
	printf("%c", '\n');
	printf("%s", (char *)memchr(str, c, 10));
	return (0);
}
*/