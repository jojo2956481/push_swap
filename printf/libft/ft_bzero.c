/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:26:04 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:26:13 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	c = (unsigned char *)s;
	i = 0;
	while (i < n)
		c[i++] = '\0';
}
/*
#include "stdio.h"

int    main(void)
{
    char d[6];
    ft_bzero(d, 6);
    printf("%s\n", d);
}*/
