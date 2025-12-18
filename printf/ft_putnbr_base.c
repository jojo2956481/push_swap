/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:22:09 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 10:01:45 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_base(unsigned int n, int swbase)
{
	unsigned int	base_len;

	base_len = ft_strlen_p(base(swbase));
	if (n >= base_len)
		ft_putnbr_base((n / base_len), swbase);
	write(1, &base(swbase)[n % base_len], 1);
	return (ft_intlen_base(n));
}
