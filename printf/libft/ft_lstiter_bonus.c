/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:21:17 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 13:21:19 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	to_upper_test(void *content)
{
	char *str = (char *)content;
	int i = 0;

	while (str[i])
	{
		str[i] -= 32;
		i++;
	}
}

#include <stdio.h>

int	main(void)
{
	int i = 0;
	t_list *node;
	t_list *node1;

	node1 = ft_lstnew(ft_strdup("echo"));
	while (i < 10)
	{
		node = ft_lstnew(ft_strdup("echo"));
		ft_lstadd_back(&node1, node);
		i++;
	}
	ft_lstiter(node1, to_upper_test);
	while (node1)
	{
		printf("%s\n", (char *)node1->content);
		node1 = node1->next;
	}
	return (0);
}*/