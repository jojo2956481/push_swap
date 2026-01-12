/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:43:07 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/27 10:43:09 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_first_line_until_newline(int fd, char **reste, char *buf)
{
	int		n;
	char	*tmp;

	while (ft_strchr(*reste, '\n') == NULL)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (-1);
		if (n == 0)
			break ;
		buf[n] = '\0';
		tmp = *reste;
		if (*reste)
			*reste = ft_strjoin(*reste, buf);
		else
			*reste = ft_strdup(buf);
		if (tmp)
			free(tmp);
		if (!*reste)
			return (-1);
	}
	return (0);
}

void	get_first_line(char **reste, char **line)
{
	char	*newline;
	char	*tmp;
	size_t	line_len;
	size_t	new_reste_len;

	newline = ft_strchr(*reste, '\n');
	if (newline)
	{
		line_len = (size_t)(newline - *reste + 1);
		new_reste_len = ft_strlen(*reste) - line_len;
		*line = ft_substr(*reste, 0, line_len);
		tmp = ft_substr(*reste, line_len, new_reste_len);
		free(*reste);
		*reste = tmp;
	}
	else
	{
		*line = ft_strdup(*reste);
		free(*reste);
		*reste = NULL;
	}
}

static void	free_all(char **reste, char **buf)
{
	free(*buf);
	if (reste)
		free(*reste);
	*reste = NULL;
}

char	*get_next_line(int fd)
{
	static char	*reste;
	char		*line;
	char		*buf;

	line = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (get_first_line_until_newline(fd, &reste, buf) == -1)
		return (free_all(&reste, &buf), NULL);
	if (!reste || *reste == '\0')
		return (free_all(&reste, &buf), NULL);
	get_first_line(&reste, &line);
	free(buf);
	return (line);
}
