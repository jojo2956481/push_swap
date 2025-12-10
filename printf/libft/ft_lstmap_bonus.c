/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:23:10 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/11 13:23:14 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
void *to_upper(void *content)
{
	char *str = (char *)content;
	char *new_str = malloc(ft_strlen(str) + 1);
	int i = 0;

	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = ft_toupper((unsigned char)str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// Fonction del : libère la mémoire d’un élément
void del(void *content)
{
	free(content);
}

// Fonction utilitaire pour afficher la liste
void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
int main(void)
{
	// Création d'une liste de chaînes
	t_list *lst = NULL;
	t_list *mapped = NULL;

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("libft")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("42")));

	printf("Liste originale :\n");
	print_list(lst);

	// Application de ft_lstmap
	mapped = ft_lstmap(lst, to_upper, del);

	printf("\nListe mappée :\n");
	print_list(mapped);

	// Nettoyage
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped, del);

	return (0);
}*/