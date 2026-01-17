/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:25:04 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/17 09:25:05 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static int	get_action(t_order *lst, int type)
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

static void	print_adaptive(int algo)
{
	ft_printf("[bench] strategy: Adaptive ");
	if (algo == 1)
		ft_printf("O(n²)\n");
	if (algo == 2)
		ft_printf("O(n√n)\n");
	if (algo == 3)
		ft_printf("(n log n)\n");
}

//0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr
void	display_bench(float disorder, int strat, t_actions *a, int algo)
{
	int	disorder_first;
	int	disorder_last;

	disorder_first = disorder * 100;
	disorder_last = disorder * 10000 - disorder_first * 100;
	ft_printf("[bench] disorder: %d.%d%%\n", disorder_first, disorder_last);
	if (strat == 1)
		ft_printf("[bench] strategy: Simple O(n²)\n");
	else if (strat == 2)
		ft_printf("[bench] strategy: Medium O(n√n)\n");
	else if (strat == 3)
		ft_printf("[bench] strategy: Complex O(n log n)\n");
	else if (strat == 0)
		print_adaptive(algo);
	ft_printf("[bench] total_ops: %d\n", a->nb_op);
	ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		get_action(a->lst, 0), get_action(a->lst, 1), get_action(a->lst, 2),
		get_action(a->lst, 3), get_action(a->lst, 4));
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		get_action(a->lst, 5), get_action(a->lst, 6), get_action(a->lst, 7),
		get_action(a->lst, 8), get_action(a->lst, 9), get_action(a->lst, 10));
}
