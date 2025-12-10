/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 08:21:40 by pgougne           #+#    #+#             */
/*   Updated: 2025/11/21 08:22:48 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_printf
{
	char		type;
	void		*content;
	char		*sup_args;
	int			place;
	void		*next;
}	t_printf;

t_printf	*lst_built(const char *str);
char		*ft_itoa_u(unsigned int n);
int			ft_printf(const char *str, ...);
t_printf	*lst_new(char type, char *sup_args, int place);
void		lst_add_back(t_printf *lst, t_printf *new);
t_printf	*create_lst(char type, char *sup_arg, t_printf *lst, int place);
char		*ft_strndup(const char *s, size_t len);
void		free_lst(t_printf *lst);
char		*base_p(void *ptr);
char		*ft_itoa_base(unsigned int n, char *base);
char		*ft_itoa_base_int(long n, char *base);
void		man_c(t_printf *lst, int arg);
t_printf	*lst_print(t_printf *lst, int *i, int *count);
int			bon_arg_man(char **sup_arg, const char *str, int *i);
int			fill_content(t_printf *lst, va_list args);
char		bonus_type(char *sup_arg, int *size);
int			is_in_tab(char c, char *tab);
int			print_content(char *str, char type);
int			print_bonus_zero(t_printf *lst, int size, char *str);
int			print_bonus_dash(t_printf *lst, int size, char *str);
int			print_bonus_point(int size, char *str);
int			print_bonus_front_spaces(t_printf *lst, int size, char *str);
int			print_bonus_plus(t_printf *lst, char *str);
int			print_bonus_hash(t_printf *lst, char *str);
int			print_bonus_space(char *str);

#endif //FT_PRINTF_H
