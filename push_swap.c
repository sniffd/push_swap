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

void	reset(t_stack *current)
{
	current->ra = 0;
	current->rb = 0;
	current->rr = 0;
	current->rra = 0;
	current->rrb = 0;
	current->rrr = 0;
	current->sum = 0;
}

void	set_b(t_stack *current, t_pointers *pntrs, t_counters *cntrs)
{
	t_stack	*tmp;

	tmp = current;
	if ((current->rb = find_steps(pntrs->b_first, cntrs->counter_b, current->data)) < 0)
	{
		current->rb = 0;
		while (tmp != pntrs->b_first)
		{
			(current->rrb)++;
			tmp = tmp->next;
		}
	}
}

void	optimization(t_stack *current)
{
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

void	set_op(t_pointers *pntrs, int argc, int *ar, t_counters *cntrs)
{
	int		part;
	int		i;
	int		j;
	t_stack	*current;
	t_stack	*tmp;

	current = pntrs->b_first;
	part = 0;
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
		reset(current);
		if (part == current->part)
		{
			set_b(current, pntrs, cntrs);
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
				if (is_contain(pntrs->a_first, cntrs->counter_a, ar[i + j]))
					break;
				j++;
			}
			tmp = pntrs->a_first;
			if ((current->ra = find_steps(pntrs->a_first, cntrs->counter_a, ar[i + j])) == -1)
			{
				current->ra = 0;
				while (tmp->data != ar[i + j])
				{
					(current->rra)++;
					tmp = tmp->prev;
				}
			}
			optimization(current);
		}
		current = current->next;
		if (current == pntrs->b_first)
			break;
	}
}

t_stack		*get_steps(t_stack *first, t_counters *cntrs)
{
	int	part;
	int	min;
	t_stack *current;
	t_stack *res;

	current = first;
	res = current;
	part = 0;
	if (cntrs->t_counter > 0)
		part = 3;
	else if (cntrs->s_counter > 0)
		part = 2;
	else if (cntrs->f_counter > 0)
		part = 1;
	min = -1;
	while (1)
	{
		if (current->part == part && (current->sum < min || min < 0))
		{
			min = current->sum;
			res = current;
		}
		if (current == first->prev)
			break;
		current = current->next;
	}
	return (res);
}

void	do_op(t_pointers *pntrs, t_stack *current, int *counter, void (fn)(t_pointers *, int))
{
		while (*counter > 0)
		{
			fn(pntrs, 1);
			(*counter)--;
		}
}

void	execute(t_pointers *pntrs, t_counters *cntrs)
{
	t_stack	*ops;

	ops = get_steps(pntrs->b_first, cntrs);
	do_op(pntrs, ops, &(ops->rr), &rr);
	do_op(pntrs, ops, &(ops->ra), &ra);
	do_op(pntrs, ops, &(ops->rb), &rb);
	do_op(pntrs, ops, &(ops->rrr), &rrr);
	do_op(pntrs, ops, &(ops->rra), &rra);
	do_op(pntrs, ops, &(ops->rrb), &rrb);
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

void	push_part(t_pointers *pntrs, t_counters *cntrs, int steps, int part)
{
	if (part == 3)
		cntrs->tmp = cntrs->t_counter;
	else if (part == 2)
		cntrs->tmp = cntrs->s_counter;
	else
		cntrs->tmp = cntrs->f_counter;
	while ((cntrs->tmp)--)
	{
		if (pntrs->a_first->part == part)
			pb(pntrs);
		else if ((steps = find_elem(pntrs->a_first, part)) > 0)
		{
			while (steps--)
				ra(pntrs, 1);
			pb(pntrs);
		}
		else
		{
			while (steps++)
				rra(pntrs, 1);
			pb(pntrs);
		}
		(cntrs->counter_a)--;
		(cntrs->counter_b)++;
	}
}

void	presort(t_pointers *pntrs, t_counters *cntrs)
{
	int	steps;

	steps = 0;
	push_part(pntrs, cntrs, steps, 3);
	push_part(pntrs, cntrs, steps, 2);
	push_part(pntrs, cntrs, steps, 1);
}

void	mark_up(t_pointers *pntrs, t_counters *cntrs, const int *ar)
{
	t_stack		*current;
	int			i;
	int			first_index;
	int			second_index;

	current = pntrs->a_first;
	first_index = (cntrs->counter_a - 1) / 3;
	second_index = first_index * 2 + 1;
	while (1)
	{
		i = 0;
		while (ar[i] != current->data)
			i++;
		if (i <= first_index && i != 0 && (current->part = 1))
			(cntrs->f_counter)++;
		else if (i < second_index && i != 0 && (current->part = 2))
			(cntrs->s_counter)++;
		else if (i < cntrs->counter_a - 1 && i != 0 && (current->part = 3))
			(cntrs->t_counter)++;
		if (current == pntrs->a_last)
			break ;
		current = current->next;
	}
}

void	final_rotation(t_pointers *pntrs, t_counters *cntrs, const int *ar)
{
	int	steps;

	if ((steps = find_steps(pntrs->a_first, cntrs->counter_a, ar[0])) != 0)
	{
		if (steps < 0)
			while (pntrs->a_first->data != ar[0])
				rra(pntrs, 1);
		else
			while (pntrs->a_first->data != ar[0])
				ra(pntrs, 1);
	}
}

void	push_swap(t_pointers *pntrs, int *ar, int argc)
{
	t_counters	*cntrs;

	if (is_sort(pntrs->a_first, pntrs->a_last))
		return ;
	cntrs = (t_counters *)ft_memalloc(sizeof(t_counters));
	cntrs->counter_a = argc - 1;
	mark_up(pntrs, cntrs, ar);
	presort(pntrs, cntrs);
	while (cntrs->counter_b)
	{
		set_op(pntrs, argc, ar, cntrs);
		pntrs->b_last = pntrs->b_first->prev;
		execute(pntrs, cntrs);
		pa(pntrs);
		(cntrs->counter_a)++;
		(cntrs->counter_b)--;
	}
	final_rotation(pntrs, cntrs, ar);
//	ft_printf("stack a\n");
//	print_stack(first, first->prev);
//	ft_printf("stack b\n");
//	print_stack(b_first, b_first->prev);
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

void	create_stack(t_pointers *pntrs, int *ar, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_last(pntrs, create_elem(ar[i - 1]));
		i++;
	}
}

int		main(int argc, char **argv)
{
	int			*ar;
	int			i;
	t_pointers	*pntrs;

	pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers));
	i = 1;
	if (validation(argc, argv))
	{
		ar = (int *)ft_memalloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			ar[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		create_stack(pntrs, ar, argc);
		ft_qsort(ar, argc - 2);
		push_swap(pntrs, ar, argc);
	}
	else
		ft_printf("Error\n");
	return (0);
}