#include "push_swap.h"

int		find_steps(t_stack *first, int size, int n)
{
	int	s;

	s = 0;
	while (s <= size / 2)
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

void	print_stack(t_stack *f, t_stack *l)
{
	t_stack *tmp;

	tmp = f;
	while (1)
	{
		ft_printf("%i\n", tmp->data);
		if (tmp == l)
			break;
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	set_op(t_stack *a_first, t_stack *b_first, int size_a, int size_b, int argc, int *ar, t_counters *cntrs)
{
	int		part;
	int		i;
	int		j;
	t_stack	*current;
	t_stack	*tmp;

	current = b_first;
	if (cntrs->t_counter > 0)
		part = 3;
	else if (cntrs->s_counter > 0)
		part = 2;
	else if (cntrs->f_counter > 0)
		part = 1;
	while (1)
	{
//		ft_printf("stack a\n");
//		print_stack(a_first, a_first->prev);
//		ft_printf("stack b\n");
//		print_stack(b_first, b_first->prev);

		current->ra = 0;
		current->rb = 0;
		current->rr = 0;
		current->rra = 0;
		current->rrb = 0;
		current->rrr = 0;
		current->sum = 0;
		tmp = current;
		if (part == current->part)
		{
			if ((current->rb = find_steps(b_first, size_b, current->data)) < 0)
			{
				current->rb = 0;
				while (tmp != b_first)
				{
					(current->rrb)++;
					tmp = tmp->prev;
				}
			}
			i = find_pos(ar, current->data);
			j = 1;
			while (1)
			{
				if (i + j == argc - 1)
				{
					i = 0;
					j = 0;
					break ;
				}
				if (is_contain(a_first, size_a, ar[i + j]))
					break;
				j++;
			}
			tmp = a_first;
			if ((current->ra = find_steps(a_first, size_a, ar[i + j])) == -1)
			{
				current->ra = 0;
				while (tmp->data != ar[i + j])
				{
					(current->rra)++;
					tmp = tmp->prev;
				}
			}
			while (current->ra > 0 && current->rb > 0)
			{
				(current->rr)++;
				(current->ra)--;
				(current->rb)--;
			}
			while (current->rra > 0 && current->rrb > 0)
			{
				(current->rrr)++;
				(current->rra)--;
				(current->rrb)--;
			}
			current->sum =
					current->ra + current->rb + current->rr + current->rra +
					current->rrb + current->rrr;
		}
		current = current->next;
		if (current == b_first)
			break;
	}
}

t_stack		*get_steps(t_stack *first)
{
	int	part;
//	int	steps;
//	int	res_steps;
	int	min;
	t_stack *current;
	t_stack *res;

	current = first;
	res = current;
	part = current->part;
//	steps = 0;
//	res_steps = 0;
	min = current->sum;
	while (1)
	{
		if (current->part == part && current->sum < min)
		{
			min = current->sum;
			res = current;
		}
		current = current->next;
		if (current == first->prev)
			break;
	}
	return (res);
}

void	execute(t_stack **a_first, t_stack **a_last, t_stack **b_first, t_stack **b_last, t_counters *cntrs)
{
	t_stack	*ops;

	ops = get_steps(*b_first);
	while (ops->rr > 0)
	{
		rr(a_first, a_last, b_first, b_last);
		(ops->rr)--;
	}
	while (ops->ra > 0)
	{
		ra(a_first, a_last, 1);
		(ops->ra)--;
	}
	while (ops->rb > 0)
	{
		rb(b_first, b_last, 1);
		(ops->rb)--;
	}
	while (ops->rrr > 0)
	{
		rrr(a_first, a_last, b_first, b_last);
		(ops->rrr)--;
	}
	while (ops->rra > 0)
	{
		rra(a_first, a_last, 1);
		(ops->rra)--;
	}
	while (ops->rrb > 0)
	{
		rrb(b_first, b_last, 1);
		(ops->rrb)--;
	}
	if (ops->part == 3)
		(cntrs->t_counter)--;
	else if (ops->part == 2)
		(cntrs->s_counter)--;
	else if (ops->part == 1)
		(cntrs->f_counter)--;
}

int		is_sort(t_stack *first, t_stack *last)
{
	t_stack	*current;

	current = first;
	while (current != last)
	{
		if (current->next->data < current->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_swap(t_stack *first, t_stack *last, int *ar, int argc)
{
	int steps;
	int b_steps;
	int	i;
	int	j;
	int	first_index;
	int	second_index;
	t_stack		*b_first;
	t_stack		*b_last;
	t_stack		*current;
	t_counters	*cntrs;

	if (is_sort(first, last))
		return ;
	cntrs = ft_memalloc(sizeof(t_counters));
	b_first = NULL;
	b_last = NULL;
	current = first;
	cntrs->f_counter = 0;
	cntrs->s_counter = 0;
	cntrs->t_counter = 0;
	cntrs->counter_b = 0;
	cntrs->counter_a = argc - 1;
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
			(cntrs->f_counter)++;
		}
		else if (i < second_index && i != 0)
		{
			current->part = 2;
			(cntrs->s_counter)++;
		}
		else if (i < (argc - 2) && i != 0)
		{
			current->part = 3;
			(cntrs->t_counter)++;
		}
		i = 0;
		if (current == last)
			break ;
		current = current->next;
	}
	cntrs->tmp = cntrs->f_counter;
	while (cntrs->tmp)
	{
		if (first->part == 1)
		{
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		else if ((steps = find_elem(first, 1)) > 0)
		{
			while (steps)
			{
				ra(&first, &last, 1);
				steps--;
			}
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		else
		{
			while (steps)
			{
				rra(&first, &last, 1);
				steps++;
			}
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		(cntrs->counter_a)--;
		(cntrs->counter_b)++;
	}
	cntrs->tmp = cntrs->s_counter;
	while (cntrs->tmp)
	{
		if (first->part == 2)
		{
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		else if ((steps = find_elem(first, 2)) > 0)
		{
			while (steps)
			{
				ra(&first, &last, 1);
				steps--;
			}
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		else
		{
			while (steps)
			{
				rra(&first, &last, 1);
				steps++;
			}
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		(cntrs->counter_a)--;
		(cntrs->counter_b)++;
	}
	cntrs->tmp = cntrs->t_counter;
	while (cntrs->tmp)
	{
		if (first->part == 3)
		{
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		else if ((steps = find_elem(first, 3)) > 0)
		{
			while (steps)
			{
				ra(&first, &last, 1);
				steps--;
			}
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		else
		{
			while (steps)
			{
				rra(&first, &last, 1);
				steps++;
			}
			pb(&first, &b_first);
			(cntrs->tmp)--;
		}
		(cntrs->counter_a)--;
		(cntrs->counter_b)++;
	}
	while (cntrs->counter_b)
	{
		set_op(first, b_first, cntrs->counter_a, cntrs->counter_b, argc, ar, cntrs);
		b_last = b_first->prev;
		execute(&first, &last, &b_first, &b_last, cntrs);
		pa(&first, &b_first);
		(cntrs->counter_a)++;
		(cntrs->counter_b)--;
//		i++;
	}
	if ((steps = find_steps(first, cntrs->counter_a, ar[0])) != 0)
	{
		if (steps < 0)
		{
			while (first->data != ar[0])
				rra(&first, &last, 1);
		}
		else
		{
			while (first->data != ar[0])
				ra(&first, &last, 1);
		}
	}
	ft_printf("stack a\n");
	print_stack(first, first->prev);
	ft_printf("stack b\n");
	print_stack(b_first, b_first->prev);
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