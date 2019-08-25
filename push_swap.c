#include "push_swap.h"

int		find_steps(t_stack *first, int size, int n)
{
	int	s;

	s = 0;
	while (s != size / 2)
	{
		if (n == first->data)
			return (s);
		first = first->next;
		s++;
	}
	return (-1);
}

void	push_swap(t_stack *first, t_stack *last, int *ar, int argc)
{
	int counter_a;
	int counter_b;
	int steps;
	int	i;
	t_stack	*b_first;
	t_stack	*b_last;

	b_first = NULL;
	b_last = NULL;
	counter_b = 0;
	counter_a = argc;
	i = 0;
	while (i < argc - 1)
	{
		steps = find_steps(first, counter_a, ar[i]);
		if (steps == 1 && i + 1 < argc - 1 && first->data == ar[i + 1])
			sa(&first);
		else if (steps == -1)
		{
			while (first->data != ar[i])
				rra(&first, &last);
		}
		else
		{
			while (steps > 0)
			{
				ra(&first, &last);
				steps--;
			}
		}
		pb(&first, &b_first);
		counter_b++;
		i++;
	}
	while (counter_b--)
		pa(&first, &b_first);
}

int		validation(int argc, char **argv)
{
	int	i;
	int	f;
	int *ar;

	i = 1;
	ar = ft_memalloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		f = 0;
		ar[i - 1] = atoi_push_swap(argv[i], &f);
		if (f)
			return (0);
		i++;
	}
	ft_qsort(ar, argc - 1);
	i = 0;
	while (i < argc - 2)
	{
		if (ar[i] == ar[i + 1])
			return (0);
		i++;
	}
	free(ar);
	return (1);
}

void	create_stack(t_stack **first, t_stack **last, int *ar, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_last(first, last, create_elem(ar[i - 1]));
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	*ar;
	int	i;
	t_stack *first;
	t_stack *last;

	i = 1;
	first = NULL;
	last = NULL;
	if (validation(argc, argv))
	{
		ar = (int *)ft_memalloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			ar[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		create_stack(&first, &last, ar, argc);
		ft_qsort(ar, argc - 1);
		push_swap(first, last, ar, argc);
//		i = 0;
//		while (i < argc - 1)
//		{
//			ft_printf("%i ", ar[i]);
//			i++;
//		}
	}
	else
		ft_printf("Error\n");
	return (0);
}