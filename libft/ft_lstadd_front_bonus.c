/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:51:51 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/13 15:51:36 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	temp = *lst;
	*lst = new;
	new->next = temp;
}

/*
int	main(void)
{
	t_list	*list0 = ft_lstnew("premier");
	t_list	*list1 = ft_lstnew("deuxieme");
	t_list	*list2 = ft_lstnew("troisieme");

	ft_lstadd_front(&list2, list1);
	ft_lstadd_front(&list2, list0);

	t_list *temp = list2;
    while (temp != NULL)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
}
*/