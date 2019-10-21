/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:50 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:31:50 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_op(t_pointers *pntrs, int *ar, t_counters *cntrs)
{
	int		part;

	pntrs->current = pntrs->b_first;
	part = 0;
	if (cntrs->t_counter > 0)
		part = 3;
	else if (cntrs->s_counter > 0)
		part = 2;
	else if (cntrs->f_counter > 0)
		part = 1;
	while (1)
	{
		reset(pntrs->current);
		set_sum(cntrs, pntrs, ar, part);
		pntrs->current = pntrs->current->next;
		if (pntrs->current == pntrs->b_first)
			break ;
	}
}

t_stack	*get_steps(t_stack *first, t_counters *cntrs)
{
	int		part;
	int		min;
	t_stack	*current;
	t_stack	*res;

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
		if (current->part == part && (current->sum < min || min < 0) &&
		(min = current->sum))
			res = current;
		if (current == first->prev)
			break ;
		current = current->next;
	}
	return (res);
}

void	do_op(t_pointers *pntrs, int *counter,
		void (fn)(t_pointers *, int))
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
	do_op(pntrs, &(ops->rr), &rr);
	do_op(pntrs, &(ops->ra), &ra);
	do_op(pntrs, &(ops->rb), &rb);
	do_op(pntrs, &(ops->rrr), &rrr);
	do_op(pntrs, &(ops->rra), &rra);
	do_op(pntrs, &(ops->rrb), &rrb);
	if (ops->part == 3)
		(cntrs->t_counter)--;
	else if (ops->part == 2)
		(cntrs->s_counter)--;
	else if (ops->part == 1)
		(cntrs->f_counter)--;
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
