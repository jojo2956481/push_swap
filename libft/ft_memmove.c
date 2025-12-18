/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:50:36 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:11:36 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (0);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	if (dest >= src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dest);
}

/*
int	main(void)
{
	size_t n;
	n = 33;
	const char	*src = "thi\xffs i\xfas \0a g\xde\xadood \0nyan\0cat\0 !\r\n";
	char	*dest;
	char	*dest1;
	dest1 = calloc(sizeof(char) * 45, '8');
	dest = calloc(sizeof(char) * 45, '8');
	memmove(dest, src, n);
	//memcpy(dest1, src, n);
	ft_memmove(dest1, src, n);

	printf("%s", dest);
	printf("%c", '\n');
	printf("%s", dest1);	
}
*/