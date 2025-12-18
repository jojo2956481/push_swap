/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:10:17 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:11:02 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	size_t n;
	n = 0;
	const char	*src = "je suis leo";
	char	*dest;
	//char	*dest1;
	//dest1 = calloc(sizeof(char) * 21, '\0');
	dest = calloc(sizeof(char) * 21, '5');
	memcpy(dest, src, n);
	//ft_memcpy(dest1, src, 17);

	printf("%s", dest);
	printf("%c", '\n');
	//printf("%s", dest1);	
}
*/