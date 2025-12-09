/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 08:47:54 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 08:48:04 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c < 65 || c > 122)
		return (0);
	if (c > 90 && c < 97)
		return (0);
	else
		return (1);
}

/*int	main(void)
{
	printf("%d", ft_isalpha(100));
	printf("%s", "\n");
	printf("%d", isalpha(100));
	return (0);
}
*/
