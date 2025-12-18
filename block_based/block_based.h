/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_based.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgougne <pgougne@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:12:56 by pgougne           #+#    #+#             */
/*   Updated: 2025/12/13 09:13:00 by pgougne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_BASED_H
# define BLOCK_BASED_H

void	sort_by_blocks(int *tab_a, int *size_a);
int		*block_sort(int *tab_a, int	*tab_b, int *size_a, int *size_b);

#endif
