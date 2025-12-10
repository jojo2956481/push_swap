/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_basic_case_and_first_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:20:11 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/20 08:20:12 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_content(char *str, char type)
{
	int	j;

	j = 0;
	if (str[j] == '\0' && type == 'c')
		write(1, &str[j++], 1);
	while (str[j])
		write(1, &str[j++], 1);
	return (j);
}

int	print_bonus_zero(t_printf *lst, int size, char *str)
{
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(lst->content);
	while (size > len++)
		write(1, "0", 1);
	while (str[j])
		write(1, &str[j++], 1);
	return (size);
}

int	print_bonus_dash(t_printf *lst, int size, char *str)
{
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(lst->content);
	while (str[j])
		write(1, &str[j++], 1);
	while (size > len++)
		write(1, " ", 1);
	return (size);
}

int	print_bonus_point(int size, char *str)
{
	int		j;

	j = 0;
	while (str[j] && j < size)
		write(1, &str[j++], 1);
	return (size);
}

int	print_bonus_front_spaces(t_printf *lst, int size, char *str)
{
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(lst->content);
	while (size > len++)
		write(1, " ", 1);
	while (str[j])
		write(1, &str[j++], 1);
	return (size);
}
