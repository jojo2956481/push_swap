/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:28:11 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:28:13 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
		p[i++] = (unsigned char)c;
	return (s);
}
/*
#include "stdio.h"

int    main(void)
{
    char s[10];
    int    i;
    i = 0;
    ft_memset(s, 'x', sizeof(s));
	printf("%s", s);
}*/
