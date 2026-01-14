// FAUT FAIRE UNE LIST CHAINÉE DANS t_actions pour garder la suite
int checker(int *tab_a, int size_a)
{
	int i;
	int j;
	char *action;
	int *tab_b;
	int	size;

	tab_checker = ft_calloc(size, sizeof(int));
	if (tab_checker == NULL)
	{
		free(tab);
		return (1);
	}
	size = check_args(argc - 1, argv);
	if (size == 0)
	{
		ft_printf("%s\n", "Error");
		return (1);
	}
	tab = ft_calloc(size, sizeof(int));
	if (tab == NULL)
		return (1);
	tab_b = ft_calloc(size, sizeof(int));
	if (tab_b == NULL)
	{
		free(tab);
		free(tab_checker);
		return (1);
	}
	size_b = 0;
	i = 0;
	tab_b = ft_calloc(size_a, sizeof(int));
	if (!tab_b)
		return (-1);
	while (i < 31)
	{
 		action = get_next_line(1);
		if (ft_strncmp(action, "pa", 2))
			pa(tab_a, tab_b, &size_a, &size_b);
		else if (ft_strncmp(action, "ra", 2))
			ra(tab_a, size_a);
		else if (ft_strncmp(action, "sa", 2))
			sa(tab_a, size_a);
		else if (ft_strncmp(action, "rra", 3))
			rra(tab_a, size_a);
		else if (ft_strncmp(action, "pb", 2))
			pb(tab_a, tab_b, &size_a, &size_b);
		else if (ft_strncmp(action, "rb", 2))
			rb(tab_b, size_b);
		else if (ft_strncmp(action, "sb", 2))
			sb(tab_b, size_b);
		else if (ft_strncmp(action, "rrb", 3))
			rrb(tab_b, size_b);
		else if (ft_strncmp(action, "ss", 2))
			ss(tab_b, tab_a, size_a, size_b);
		else if (ft_strncmp(action, "rr", 2))
			rr(tab_b, tab_a, size_b, size_a);
		else if (ft_strncmp(action, "rrr", 3))
			rrr(tab_b, tab_a, size_b, size_a);
		else
			ft_printf("%s\n", action);
		free(action);
		i++;
	}
	free(tab_b);
	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (tab_a[j] == tab_a[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}