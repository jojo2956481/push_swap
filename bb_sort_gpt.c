void	print(int *tab_a, int *tab_b)
{
	int i = 0;
	__builtin_printf("|-----------------|\n");
	__builtin_printf("| tab_a     tab_b |\n");
	__builtin_printf("|-----------------|\n");
	if (tab_b == NULL)
	{
		while (i < 10)
		{
			__builtin_printf("|% 4d   |\n", tab_a[i]);
			i++;
		}
		__builtin_printf("\n\n\n");
		return ;
	}
	while (i < 10)
	{
		__builtin_printf("|% 4d   || % 4d   |\n", tab_a[i], tab_b[i]);
		i++;
	}
	__builtin_printf("\n\n\n");
}


int position_of_value(t_stack *s, int v)
{
	int i = 0;

	while (s)
	{
		if (s->value == v)
			return i;
		s = s->next;
		i++;
	}
	return -1;
}

int exists_in_range(t_stack *a, int low, int high)
{
	while (a)
	{
		if (a->value >= low && a->value <= high)
			return 1;
		a = a->next;
	}
	return 0;
}


int find_stack_max(t_stack *s)
{
	int max = s->value;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return max;
}


int find_stack_min(t_stack *s)
{
	int min = s->value;
	while (s)
	{
		if (s->value < min)
			min = s->value;
		s = s->next;
	}
	return min;
}

void    push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		int max = find_stack_max(*b);
		int pos = position_of_value(*b, max);
		int mid = stack_size(*b) / 2;

		if (pos <= mid)
			while ((*b)->value != max)
				rb(b);
		else
			while ((*b)->value != max)
				rrb(b);

		pa(a, b);
	}
}


void    push_block_to_b(t_stack **a, t_stack **b, int low, int high)
{
	int size = stack_size(*a);
	int pushed = 0;

	while (pushed < size && exists_in_range(*a, low, high))
	{
		if ((*a)->value >= low && (*a)->value <= high)
		{
			pb(a, b);           // element in block → go B
			pushed++;

			// Garder B approximativement triée
			if (*b && (*b)->next && (*b)->value < (*b)->next->value)
				rb(b);          // small correction
		}
		else
			ra(a);              // rotate A until we find a block element
	}
}

void    block_sort(t_stack **a, t_stack **b)
{
	int size = stack_size(*a);
	int block_size = size / 5;       // 5 blocs → bon compromis
	int min = find_stack_min(*a);
	int max = find_stack_max(*a);
	int range = max - min;
	int i = 0;

	while (i < 5)
	{
		int lower = min + (range * i) / 5;
		int upper = min + (range * (i + 1)) / 5;

		push_block_to_b(a, b, lower, upper);
		i++;
	}

	push_back_to_a(a, b);
}

#include <stdio.h>
int main(void)
{
	int tab_a[10] = {4,8,7, 3,6,2, 5,9,1};
	int size_a = 9;
	tab_a = block_sort(tab_a, &size_a);
	int i = 0;
	__builtin_printf("tab_a\n");
	while (i < size_a)
	{
		__builtin_printf("% 4d\n", tab_a[i]);
		i++;
	}
	__builtin_printf("\n\n\n");
	free(tab_b);
	return 0;
}