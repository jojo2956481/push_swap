/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:58:27 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 09:58:30 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	*lst = new;
	new->next = tmp;
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

	ft_lstadd_front(&lst, new);
	ft_lstadd_front(&lst, new2);
	printf("%s\n", (char *)lst->content);
	printf("%s\n", (char *)lst->next->content);

	return (0);
}*/