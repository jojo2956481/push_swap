/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:33:34 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 11:29:41 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	del(void *content)
{
	if (content != NULL)
		content = NULL;
}

static void	*f(void *s)
{
	char	*str = (char *)s;

	if (str != NULL)
	{
		str[0] = str[0] - 32;
	}
	return (str);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
int	main(void)
{
	t_list *temp;

	t_list	*list0 = ft_lstnew(ft_strdup("premier"));
	t_list	*list1 = ft_lstnew(ft_strdup("dexieme"));
	t_list	*list2 = ft_lstnew(ft_strdup("troisieme"));

	list0->next = list1;
	list1->next = list2;

	temp = list0;
	while (temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
	printf("%c", '\n');

	temp = ft_lstmap(list0, f, del);
	while (temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
}
*/