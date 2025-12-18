/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:23:02 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/11/17 09:13:30 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

/*
int main(void)
{
	const char	*str = "teste";
	char	c;
	c = 'e';

	printf("%s", ft_strchr(str, c));
	printf("%c", '\n');
	printf("%s", strchr(str, c));
	return (0);
}
*/
