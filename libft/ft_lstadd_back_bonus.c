/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:01:35 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/14 11:42:05 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

/*
int	main(void)
{
	t_list	*list0 = ft_lstnew("premier");
	t_list	*list1 = ft_lstnew("deuxieme");
	t_list	*list2 = ft_lstnew("troisieme");

	ft_lstadd_back(&list0, list1);
	ft_lstadd_back(&list0, list2);

	t_list *temp = list0;
    while (temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
}
*/