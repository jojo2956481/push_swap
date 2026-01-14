#include "push_swap.h"

void	ft_lstclear(t_order **lst)
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

t_order *ft_lstnew(int content)
{
	t_order    *lstnew;

	lstnew = malloc(sizeof(t_order));
	if (!lstnew)
		return (NULL);
	lstnew->action = content;
	lstnew->next = NULL;
	return (lstnew);
}

int	get_nb_action_by_type(t_order *lst, int type)
{
	int c;

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

t_order	*ft_lstlast(t_order *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_order **lst, t_order *new)
{
	t_order	*temp;

	if (new == NULL)
	{
		ft_lstclear(lst);
		return ;
	}
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
