/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:26:56 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/14 11:09:17 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	f(void *s)
{
	char	*str = (char *)s;

	if (str != NULL)
	{
		str[0] = str[0] - 32;
	}
}
*/

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
int	main(void)
{
	t_list	*list0 = ft_lstnew(ft_strdup("premier"));
	t_list	*list1 = ft_lstnew(ft_strdup("dexieme"));
	t_list	*list2 = ft_lstnew(ft_strdup("troisieme"));

	list0->next = list1;
	list1->next = list2;

	ft_lstiter(list0, f);

	t_list *temp = list0;
    while (temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
}
*/