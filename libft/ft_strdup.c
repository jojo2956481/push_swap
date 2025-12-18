/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:57:03 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 08:57:07 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen((char *)s);
	dest = ft_calloc(size + 1, sizeof(char));
	if (dest == NULL)
		return (0);
	while ((char)s[i] != '\0')
	{
		dest[i] = (char)s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
