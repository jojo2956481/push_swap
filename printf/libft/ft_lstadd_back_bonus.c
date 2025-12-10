/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:08:26 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 11:08:27 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
/*
#include <stdio.h>
int main(void)
{
	t_list *lst = NULL;
	char *str = "Hello World!";
	char *str2 = "Hello Worlddddddd!";
	t_list *new = ft_lstnew(str);
	t_list *new2 = ft_lstnew(str2);

	ft_lstadd_back(&lst, new);
	ft_lstadd_back(&lst, new2);
	printf("%s\n", (char *)lst->content);
	printf("%s\n", (char *)lst->next->content);

	return (0);
}*/