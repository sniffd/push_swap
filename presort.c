#include "push_swap.h"

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
			pb(pntrs, 1);
		else if ((steps = find_elem(pntrs->a_first, part)) > 0)
		{
			while (steps--)
				ra(pntrs, 1);
			pb(pntrs, 1);
		}
		else
		{
			while (steps++)
				rra(pntrs, 1);
			pb(pntrs, 1);
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
