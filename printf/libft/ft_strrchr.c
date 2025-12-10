/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:29:41 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:29:42 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			n = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (n >= 0)
		return ((char *)&s[n]);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_strrchr("echoeho", 'z'));
}*/
