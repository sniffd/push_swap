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

int		is_contain(t_stack *first, int size, int n)
{
	int	s;

	s = 0;
	while (s != size)
	{
		if (n == first->data)
			return (1);
		first = first->next;
		s++;
	}
	return (0);
}

int		find_pos(const int *ar, int n)
{
	int	i;

	i = 0;
	while (ar[i] != n)
		i++;
	return (i);
}

int		find_elem(t_stack *first, int part)
{
	t_stack	*tmp;
	int		f;
	int		b;

	tmp = first;
	f = 0;
	b = 0;
	while (tmp->part != part)
	{
		tmp = tmp->next;
		f++;
	}
	tmp = first;
	while (tmp->part != part)
	{
		tmp = tmp->next;
		b--;
	}
	return (f <= -b ? f : b);
}

void	push_swap(t_stack *first, t_stack *last, int *ar, int argc)
{
	int counter_a;
	int counter_b;
	int steps;
	int b_steps;
	int	i;
	int	j;
	int	first_index;
	int	second_index;
	int	f_counter;
	int	s_counter;
	int	t_counter;
	t_stack	*b_first;
	t_stack	*b_last;
	t_stack	*current;

	b_first = NULL;
	b_last = NULL;
	current = first;
	f_counter = 0;
	s_counter = 0;
	t_counter = 0;
	counter_b = 0;
	counter_a = argc - 1;
	i = 0;
	j = 0;
	first_index = (argc - 2) / 3;
	second_index = first_index * 2 + 1;
	while (1)
	{
		while (ar[i] != current->data)
			i++;
		if (i <= first_index && i != 0)
		{
			current->part = 1;
			f_counter++;
		}
		else if (i < second_index)
		{
			current->part = 2;
			s_counter++;
		}
		else if (i < (argc - 2))
		{
			current->part = 3;
			t_counter++;
		}
		i = 0;
		if (current == last)
			break ;
		current = current->next;
	}
		while (f_counter)
		{
			if (first->part == 1)
			{
				pb(&first, &b_first);
				f_counter--;
			}
			else if ((steps = find_elem(first, 1)) > 0)
			{
				while (steps)
				{
					ra(&first, &last);
					steps--;
				}
				pb(&first, &b_first);
				f_counter--;
			}
			else
			{
				while (steps)
				{
					rra(&first, &last);
					steps++;
				}
				pb(&first, &b_first);
				f_counter--;
			}
			counter_a--;
			counter_b++;
		}
		while (s_counter)
		{
			if (first->part == 2)
			{
				pb(&first, &b_first);
				s_counter--;
			}
			else if ((steps = find_elem(first, 2)) > 0)
			{
				while (steps)
				{
					ra(&first, &last);
					steps--;
				}
				pb(&first, &b_first);
				s_counter--;
			}
			else
			{
				while (steps)
				{
					rra(&first, &last);
					steps++;
				}
				pb(&first, &b_first);
				s_counter--;
			}
			counter_a--;
			counter_b++;
		}
		while (t_counter)
		{
			if (first->part == 3)
			{
				pb(&first, &b_first);
				t_counter--;
			}
			else if ((steps = find_elem(first, 3)) > 0)
			{
				while (steps)
				{
					ra(&first, &last);
					steps--;
				}
				pb(&first, &b_first);
				t_counter--;
			}
			else
			{
				while (steps)
				{
					rra(&first, &last);
					steps++;
				}
				pb(&first, &b_first);
				t_counter--;
			}
			counter_a--;
			counter_b++;
		}
	while (counter_b)//TODO изменить алгос, чтобы считало варианты для каждого элемента
	{
		i = find_pos(ar, b_first->data);
		j = 1;
		while (i + j < argc - 1)
		{
			if (is_contain(first, counter_a, ar[i + j]))
				break;
			j++;
		}
		steps = find_steps(first, counter_a, ar[i + j]);
		if (steps == -1)
		{
			while (first->data != ar[i + j])
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
		pa(&first, &b_first);
		counter_a++;
		counter_b--;
		i++;
	}
}

int		validation(int argc, char **argv)
{
	int	i;
	int	f;
	int *ar;

	i = 1;
	ar = (int *)ft_memalloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		f = 0;
		ar[i - 1] = atoi_push_swap(argv[i], &f);
		if (f)
			return (0);
		i++;
	}
	ft_qsort(ar, argc - 2);
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
//		ft_printf("%i\n%i\n%i\n%i\n%i\n", ar[0], ar[1], ar[2], ar[3], ar[4]);
		create_stack(&first, &last, ar, argc);
		ft_qsort(ar, argc - 2);
//		ft_printf("%i\n%i\n%i\n%i\n%i\n", ar[0], ar[1], ar[2], ar[3], ar[4]);
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