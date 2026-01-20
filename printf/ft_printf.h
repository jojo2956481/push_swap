/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:17:07 by lebeyssa          #+#    #+#             */
/*   Updated: 2026/01/19 10:07:59 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(int fd, const char *str, ...);
int		ft_putchar(int fd, char c);
int		ft_putnbr(int fd, int n);
int		ft_putstr(int fd, char *s);
int		ft_loop(int fd, char *str, va_list args);
int		ft_dipatch(int fd, char c, va_list args);
int		ft_strlen_p(const char *str);
int		ft_putptr(unsigned long ptr);
int		ft_putnbr_unsigned(int fd, unsigned int n);
int		ft_putnbr_base(int fd, unsigned int n, int swbase);
int		ft_intlen_base(unsigned long int n);
char	*base(int swbase);
int		ft_putnbr_base_p(unsigned long n, int swbase);

#endif