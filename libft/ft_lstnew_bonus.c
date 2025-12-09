/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:19:51 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:17:09 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = ft_calloc(1, sizeof(t_list));
	if (lstnew == NULL)
		return (0);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

/*
int	main(void)
{
	t_list	*list1;
	char	*str;
	
	list1 = ft_lstnew("je suis leo");
	str = list1->content;
	printf("%s", str);
	return (0);
}
*/