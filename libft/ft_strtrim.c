/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:03:37 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/15 11:07:19 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_sep(char c, const char *str)
{
	int	i;

	i = 0;
	while (c != str[i])
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && find_sep(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && find_sep(s1[end - 1], set))
		end--;
	str = ft_calloc((end - start) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, (end - start) + 1);
	return (str);
}

/*
int	main(void)
{
	char	*str1 = "";
	char	*str2 = "";

	printf("%s", ft_strtrim(str1, str2));
	return (0);
}
*/