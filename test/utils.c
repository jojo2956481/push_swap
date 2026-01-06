#include "push_swap.h"

int ft_atoi(const char *str)
{
	long n = 0;
	int sign = 1;

	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			ft_error();
		n = n * 10 + (*str++ - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			ft_error();
	}
	return (n * sign);
}

void ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int is_sorted(int *tab, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
