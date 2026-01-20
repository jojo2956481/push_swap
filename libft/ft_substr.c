/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:51:55 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:47:12 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	size;

	if (s == NULL)
		return (0);
	i = 0;
	size = ft_strlen((char *)s);
	if ((size_t)start >= size)
		return (ft_calloc(1, sizeof(char)));
	if (len > (size - start))
		len = size - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = (char)s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
