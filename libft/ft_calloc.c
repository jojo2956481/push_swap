/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:12 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:46:08 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	buff;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
	{
		free(ptr);
		return (0);
	}
	buff = nmemb * size;
	if (buff / nmemb != size)
		return (NULL);
	ft_bzero(ptr, buff);
	return (ptr);
}
