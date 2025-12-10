/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:28:45 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 08:28:46 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

char	*ft_strndup(const char *s, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[i] && i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
