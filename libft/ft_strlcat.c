/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:01:09 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:01:15 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	j = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(((char *)src));
	i = len_dest;
	if (size == 0 || len_dest >= size)
		return (len_src + size);
	else
	{
		while (j < (size - 1) - len_dest && j != len_src)
		{
			dest[i++] = src[j++];
		}
		dest[i] = '\0';
		return (len_dest + len_src);
	}
}

/*
int	main(void)
{
	size_t    size;
	const char    src[] = "peluche";
    //char    dest[45] = "la";
    char    dest1[45] = "la";

    size = -1;
    printf("%d", ft_strlcat(dest1, src, size));
    printf("%s", dest1);
    printf("%c", '\n');
    //printf("%zu", strlcat(dest, src, size));
    //printf("%s", dest);
    return (0);
}
*/
