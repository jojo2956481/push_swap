/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:28:52 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:28:54 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
		return (NULL);
	join[s1_len + s2_len] = '\0';
	while (s2_len--)
		join[s2_len + s1_len] = s2[s2_len];
	while (s1_len--)
		join[s1_len] = s1[s1_len];
	return (join);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	s1 = "hello";
	s2 = "world";
	s1 = ft_strjoin(s1, s2);
	printf("%s\n", s1);
	free(s1);
}
*/