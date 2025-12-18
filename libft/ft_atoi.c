/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebeyssa <lebeyssa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:27:31 by lebeyssa          #+#    #+#             */
/*   Updated: 2025/12/10 10:28:05 by lebeyssa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *nptr)
{
	long	resultat;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	resultat = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		resultat = resultat * 10 + (nptr[i] - '0');
		i++;
	}
	return (resultat * sign);
}

/*
int main(void)
{
	char	*str = "-1000043a";
	printf("%d", atoi(str));
	printf("%c", '\n');
	printf("%d", ft_atoi(str));
	return (0);
}
*/