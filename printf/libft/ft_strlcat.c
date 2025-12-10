/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:29:00 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:29:01 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len >= size)
		return (src_len + size);
	while (dst_len + i + 1 < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[6] = "HELLO";
	char dst[18] = "H4LLO";
	char dest[18] = "H4LLO";
	int	i = ft_strlcat(dst, str, -100);
	printf("%d\n", i);
	printf("%s\n", dst);
	int	j = strlcat(dest, str, -100);
	printf("%d\n", j);
	printf("%s\n", dest);
}*/
