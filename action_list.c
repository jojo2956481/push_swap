/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:38:19 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/14 16:38:22 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelete(t_order **lst)
{
	t_order	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_order	*ft_lstcreate(int content)
{
	t_order	*lstnew;

	lstnew = malloc(sizeof(t_order));
	if (!lstnew)
		return (NULL);
	lstnew->action = content;
	lstnew->next = NULL;
	return (lstnew);
}

int	get_action(t_order *lst, int type)
{
	int	c;

	c = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->action == type)
			c++;
		lst = lst->next;
	}
	return (c);
}

t_order	*ft_lst_get_last(t_order *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lst_add_back(t_order **lst, t_order *new)
{
	t_order	*temp;

	if (new == NULL)
	{
		ft_lstdelete(lst);
		return ;
	}
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lst_get_last(*lst);
	temp->next = new;
}
