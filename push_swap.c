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

void	push_swap(t_stack *first, t_stack *last, int argc)
{
	int counter_a;
	int counter_b;
	int steps;

	counter_b = 0;
	counter_a = argc;
	steps = find_steps(first, counter_a, );
	if ()
	{

	}
	while ()
	{

	}
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

int		main(int argc, char **argv)
{
	if (validation(argc, argv))
	{

	}
	else
		ft_printf("Error\n");
	return (0);
}