#include "push_swap.h"

void	push_swap(t_pointers *pntrs, int *ar, int argc)
{
	t_counters	*cntrs;

	if (is_sort(pntrs->a_first, pntrs->a_last))
		return ;
	if (!(cntrs = (t_counters *)ft_memalloc(sizeof(t_counters))))
		exit(0);
	cntrs->counter_a = argc - 1;
	if (cntrs->counter_a == 5 || cntrs->counter_a == 3)
		five(pntrs, cntrs, ar);
	else
	{
		mark_up(pntrs, cntrs, ar);
		presort(pntrs, cntrs);
		while (cntrs->counter_b)
		{
			set_op(pntrs, ar, cntrs);
			pntrs->b_last = pntrs->b_first->prev;
			execute(pntrs, cntrs);
			pa(pntrs, 1);
			(cntrs->counter_a)++;
			(cntrs->counter_b)--;
		}
		final_rotation(pntrs, cntrs, ar);
	}
	free(cntrs);
}

int		validation(int argc, char **argv)
{
	int	i;
	int	f;
	int *ar;

	i = 1;
	if (!(ar = (int *)ft_memalloc(sizeof(int) * (argc - 1))))
		exit(0);
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

void	free_all(t_pointers *pntrs, int *ar)
{
	t_stack *tmp;
	t_stack *temp;

	free(ar);
	tmp = pntrs->a_first;
	if (tmp)
	{
		while (tmp != pntrs->a_last && ((temp = tmp->next) || 1))
		{
			free(tmp);
			tmp = temp;
		}
		free(tmp);
	}
	tmp = pntrs->b_first;
	if (tmp)
	{
		while (tmp != pntrs->b_last && ((temp = tmp->next) || 1))
		{
			free(tmp);
			tmp = temp;
		}
		free(tmp);
	}
	free(pntrs);
}

int		main(int argc, char **argv)
{
	int			*ar;
	int			i;
	t_pointers	*pntrs;

	if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
		exit(0);
	i = 1;
	if (validation(argc, argv))
	{
		if (!(ar = (int *)ft_memalloc(sizeof(int) * (argc - 1))))
			exit(0);
		while (i < argc)
		{
			ar[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		create_stack(pntrs, ar, argc);
		ft_qsort(ar, argc - 2);
		push_swap(pntrs, ar, argc);
		free_all(pntrs, ar);
	}
	else
		ft_printf("Error\n");
	return (0);
}
