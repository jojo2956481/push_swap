/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:50:53 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:16:45 by lebeyssa         ###   ########lyon.fr   */
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

/*
int	main(void)
{
	t_list	*list0 = ft_lstnew("premier");
	t_list	*list1 = ft_lstnew("deuxieme");
	t_list	*list2 = ft_lstnew("troisieme");

	list0->next = list1;
	list1->next = list2;

	ft_lstdelone(list1, del);

    printf("%s\n", (char *)list0->content);
	printf("%s\n", (char *)list2->content);
	printf("%s\n", (char *)list1->content);
}
*/