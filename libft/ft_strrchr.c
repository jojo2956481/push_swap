/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:53:49 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:47:07 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		count;
	int		temp;

	if (*s == 0 && (char)c != '\0')
		return (0);
	i = 0;
	count = 0;
	temp = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			count = i;
			temp++;
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (s[i] == '\0' && temp == 0)
		return (0);
	return ((char *)&s[count]);
}
