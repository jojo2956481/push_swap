/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:25:04 by pgougne           #+#    #+#             */
/*   Updated: 2026/01/20 09:15:02 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static void	print_adaptive(int algo)
{
	ft_printf(2, "[bench] strategy: Adaptive ");
	if (algo == 1)
		ft_printf(2, "O(n²)\n");
	if (algo == 2)
		ft_printf(2, "O(n√n)\n");
	if (algo == 3)
		ft_printf(2, "(n log n)\n");
}

//0 sa | 1 sb | 2 ss | 3 pa | 4 pb | 5 ra | 6 rb | 7 rr | 8 rra | 9 rrb | 10 rrr
void	display_bench(float disorder, int strat, t_actions *a, int algo)
{
	int	disorder_first;
	int	disorder_last;

	disorder_first = disorder * 100;
	disorder_last = disorder * 10000 - disorder_first * 100;
	ft_printf(2, "[bench] disorder: %d.%d%%\n", disorder_first, disorder_last);
	if (strat == 1)
		ft_printf(2, "[bench] strategy: Simple O(n²)\n");
	else if (strat == 2)
		ft_printf(2, "[bench] strategy: Medium O(n√n)\n");
	else if (strat == 3)
		ft_printf(2, "[bench] strategy: Complex O(n log n)\n");
	else if (strat == 0)
		print_adaptive(algo);
	ft_printf(2, "[bench] total_ops: %d\n", a->nb_op);
	ft_printf(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		a->sa, a->sb, a->ss, a->pa, a->pb);
	ft_printf(2, "[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		a->ra, a->rb, a->rr, a->rra, a->rrb, a->rrr);
}
