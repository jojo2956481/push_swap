/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:28:25 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:28:27 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_worddup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **tab, int i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
}

static void	pos_start_end(int *start, int *end, const char *s, char c)
{
	while (s[*start] == c && s[*start])
		(*start)++;
	*end = *start;
	while (s[*end] && s[*end] != c)
		(*end)++;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start])
	{
		pos_start_end(&start, &end, s, c);
		if (end > start)
		{
			split[i] = ft_worddup(s, start, end);
			if (!split[i++])
				return (ft_free_all(split, i - 1), NULL);
		}
		start = end;
	}
	split[i] = NULL;
	return (split);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**strs;
	int		i;
	i = -1;
	strs = ft_split("hello world", ' ');
	while (strs[++i])
	{
		printf("%s\n", strs[i]);
		free(strs[i]);
	}
	free(strs);
	return (0);
}
*/