/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_second_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:28:10 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/20 08:28:12 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_bonus_space(char *str)
{
	int		j;

	j = 0;
	write(1, " ", 1);
	while (str[j])
		write(1, &str[j++], 1);
	return (j + 1);
}

int	print_bonus_hash(t_printf *lst, char *str)
{
	int		j;
	int		len;

	len = ft_strlen(lst->content);
	j = 0;
	if (lst->type == 'X' && ft_strncmp(str, "0", len))
		write(1, "0X", 2);
	if (lst->type == 'x' && ft_strncmp(str, "0", len))
		write(1, "0x", 2);
	while (str[j])
		write(1, &str[j++], 1);
	return (j - 2);
}

int	print_bonus_plus(t_printf *lst, char *str)
{
	int	j;
	int	len;

	len = ft_strlen(lst->content);
	j = 0;
	if (ft_atoi(str) >= 0)
		write(1, "+", 1);
	else
		write(1, "-", 1);
	while (str[j])
		write(1, &str[j++], 1);
	return (len + 1);
}
