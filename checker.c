// FAUT FAIRE UNE LIST CHAINÉE DANS t_actions pour garder la suite
int	is_sorted(int *tab_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}