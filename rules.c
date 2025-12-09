/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:17:20 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/09 16:41:40 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// operation d'échange.
// j'ai initialisé les fonctions en int pour gérer les cas
// d'erreur.


int	sa(int *a, int size_b) // Échange les deux premiers éléments du sommet de la pile a.
{
	int temp;
	
	if (size_a =< 1)
		return (0);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (0);
}

int	sb(int *b, int size_b) // Échange les deux premiers éléments du sommet de la pile b.
{
	int temp;
	
	if (size_b =< 1)
		return (0);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	return (0);
}

int	ss(int *b, int *a, int size_a, int size_b) // Effectuer sa et sb simultanément
{
	if (size_a =< 1 || size_b =< 1)
		return (0);
	SB(b, size);
	SA(a, size);
	return (0);
}

int	pa(int *b, int *a, int size_b, int size_a) // Prendre le premier élément du sommet de b et le placer au sommet de a.
{
	if (size_b <= 0 || size_a <= 0)
		return (0)
	if (!b[0])
		return (0)
	a[0] = b[0];
}

int	pb(int *b, int *a, int size_b, int size_a) // Prend le premier élément en haut de a et le place en haut de b.
{
	if (size_b <= 0 || size_a <= 0)
		return (0)
	if (!a[0])
		return (0)
	b[0] = a[0];
}

int	ra(int *a, int size_a) // Décale tous les éléments de la pile a d'une position vers le haut.
{
	int temp;
	int	i;
	
	if (size_a < 2)
		return (0);

	temp = a[0];          
	i = 0;
	while ( i < size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}     
	a[size_a - 1] = temp;
	return (0);
}

int	rb(int *b, int size_b) // Décale tous les éléments de la pile b d'une position vers le haut.
{
	int temp;
	int	i;
	
	if (size_b < 2)
		return (0);

	temp = b[0];          
	i = 0;
	while ( i < size_a - 1)
	{
		b[i] = b[i + 1];
		i++;
	}     
	b[size_a - 1] = temp;
	return (0);
}

int rr(int *b, int *a, int size_b, int size_a) // ra et rb simultanément.
{
	if (size_b < 2 || size_a < 2 )
		return (0);
	rb(int *b, int size_b);
	ra(int *a, int size_a);
	return (0);
}

int	rra(int *a, int size_a) // Décale tous les éléments de la pile a d'une position vers le bas.
{
	int temp;
	int	i;
	
	if (size_a < 2)
		return (0);
	temp = a[size_a - 1];          
	i = size_a - 1;
	while (i >= 1)
	{
		a[i] = a[i - 1];
		i--;
	}     
	a[0] = temp;
	return (0);
}

int	rrb(int *b, int size_b) // Décale tous les éléments de la pile b d'une position vers le bas.
{
	int temp;
	int	i;
	
	if (size_b < 2)
		return (0);

	temp = b[size_b - 1];          
	i = size_b - 1;
	while (i >= 1)
	{
		b[i] = b[i - 1];
		i--;
	}     
	b[0] = temp;
	return (0);
}

int	rrr(int *b, int *a, int size_b, int size_a) // rra et rrb simultanément.
{
	if (size_b < 2 || size_a < 2)
		return (0);
	rrb(int *b, int size_b);
	rra(int *a, int size_a);
	return (0);
}



// #include <stdio.h>
// int main(void)
// {
// 	int     tab[10] = {0, 4, 7, 5, 6, 2, 9, 8, 3, 10};
// 	int     size;
// 	int     i;

// 	size = 10;
// 	i = 0;
// 	rra(tab, size);
// 	while (i < size)
// 	{
// 			printf("%d", tab[i]);
// 			i++;
// 	}
// 	return (0);
// }