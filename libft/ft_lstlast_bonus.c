/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:20:27 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/13 12:27:15 by lebeyssa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
int	main(void)
{
	t_list *temp;

	t_list	*list0 = ft_lstnew("premier");
	t_list	*list1 = ft_lstnew("deuxieme");
	t_list	*list2 = ft_lstnew("troisieme");

	list0->next = list1;
	list1->next = list2; 

	temp = ft_lstlast(list0);
	printf("%s\n", (char *)temp->content);
}
*/