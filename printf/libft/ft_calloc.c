/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:26:19 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:26:21 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str;
	str = calloc(0, 1);
	printf("%p | %s\n", str, str);
	ft_memcpy(str, "Helloworld\0", 11);
	printf("%p | %s\n", str, str);
	free(str);
	str = ft_calloc(0, 1);
	printf("%p | %s\n", str, str);
	//ft_memcpy(str, "Helloworld\0", 11);
	printf("%p | %s\n", str, str);
	free(str);

	return (0);
}
*/