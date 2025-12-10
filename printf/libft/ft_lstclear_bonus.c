/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:40:57 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 11:40:59 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void del(void *content)
// {
// 	(void)content;
// }
//
// #include <stdio.h>
// int main(void)
// {
// 	t_list *lst = NULL;
// 	char *str = "Hello World!";
// 	char *str2 = "Hello Worlddddddd!";
// 	t_list *new = ft_lstnew(str);
// 	t_list *new2 = ft_lstnew(str2);
//
// 	ft_lstadd_back(&lst, new);
// 	ft_lstadd_back(&lst, new2);
// 	printf("%s\n", (char *)lst->content);
// 	printf("%s\n", (char *)lst->next->content);
// 	ft_lstclear(&lst, &del);
// 	printf("%s\n", (char *)lst->content);
// 	printf("%s\n", (char *)lst->next->content);
//crash cae j'ai free donc oklm
// 	return (0);
// }