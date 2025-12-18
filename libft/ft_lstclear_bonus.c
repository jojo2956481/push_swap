/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:11:00 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:17:26 by lebeyssa         ###   ########lyon.fr   */
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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == NULL || !del)
		return ;
	while (*lst)
	{
		temp = ((*lst)->next);
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

/*
int	main(void)
{
	t_list	*list0 = ft_lstnew("premier");
	t_list	*list1 = ft_lstnew("deuxieme");
	t_list	*list2 = ft_lstnew("troisieme");
	t_list	*list3 = ft_lstnew("quatrieme");

	list0->next = list1;
	list1->next = list2;
	list2->next = list3;

	t_list *temp = list0;
    while (temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
	printf("%c", '\n');
	
	ft_lstclear(&list2, del);

    printf("%s\n", (char *)list0->content);
	printf("%s\n", (char *)list1->content);
	printf("%s\n", (char *)list3->content);
	printf("%s\n", (char *)list2->content);
}
*/