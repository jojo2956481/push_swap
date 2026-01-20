/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:50:53 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/20 09:48:22 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
static void	del(void *content)
{
	if (content != NULL)
		content = NULL;
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || !del)
		return ;
	del(lst->content);
	free(lst);
}
