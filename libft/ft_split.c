/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:33:29 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 11:32:18 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	cwd(char *str, char c)
{
	int	count;
	int	boul;
	int	i;

	count = 0;
	boul = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && boul == 0)
		{
			boul = 1;
			count++;
		}
		if (str[i] == c)
			boul = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

static void	*strdup_m(char *s, char set)
{
	int		size;
	char	*str;
	int		i;

	size = 0;
	if (*s == 0)
		return (0);
	while (s[size] && s[size] != set)
		size++;
	str = ft_calloc((size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

static char	**fill_tab(char *s, char c, char **str, int boul)
{
	int	i;
	int	j;

	i = 0;
	boul = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && boul == 0)
		{
			boul = 1;
			str[j] = strdup_m(&s[i], c);
			if (str[j] == NULL)
			{
				free_all(str, j);
				return (0);
			}
			j++;
		}
		if (s[i] == c)
			boul = 0;
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		boul;
	int		size;

	if (s == NULL)
		return (NULL);
	size = cwd((char *)s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (0);
	boul = 0;
	return (fill_tab((char *)s, c, str, boul));
}

/*
int	main(void)
{
	const char	*s = "hello!";
	char	p;
	int		i;

	i = 0;
	p = ' ';
	char **str = ft_split(s, p);
	while (i < 2)
	{
		printf("%s\n", str[i]);
		i++;
	}
	free_all(str, i);
	return (0);
}
*/
