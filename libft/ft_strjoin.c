/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:00:38 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:00:45 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen((char *)s1);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = ft_calloc((size + 1), sizeof(char));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(&str[len], (char *)s2, ft_strlen((char *)s2) + 1);
	return (str);
}

/*
int	main(void)
{
	const char	*str1 = "je ";
	const char	*str2 = "suis";

	printf("%s", ft_strjoin(str1, str2));
	return (0);
}
*/