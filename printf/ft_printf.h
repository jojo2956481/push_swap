/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:17:07 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 10:01:51 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_loop(char *str, va_list args);
int		ft_dipatch(char c, va_list args);
int		ft_strlen_p(const char *str);
int		ft_putptr(unsigned long ptr);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_base(unsigned int n, int swbase);
int		ft_intlen_base(unsigned long int n);
char	*base(int swbase);
int		ft_putnbr_base_p(unsigned long n, int swbase);

#endif