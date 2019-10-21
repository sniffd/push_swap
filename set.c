/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:31 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:32:31 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_b(t_pointers *pntrs, t_counters *cntrs)
{
	t_stack	*tmp;

	tmp = pntrs->current;
	if ((pntrs->current->rb =
		find_steps(pntrs->b_first, cntrs->counter_b, pntrs->current->data)) < 0)
	{
		pntrs->current->rb = 0;
		while (tmp != pntrs->b_first)
		{
			(pntrs->current->rrb)++;
			tmp = tmp->next;
		}
	}
}

void	set_a(t_pointers *pntrs, t_counters *cntrs, int e)
{
	t_stack	*tmp;

	tmp = pntrs->a_first;
	if ((pntrs->current->ra =
		find_steps(pntrs->a_first, cntrs->counter_a, e)) == -1)
	{
		pntrs->current->ra = 0;
		while (tmp->data != e)
		{
			(pntrs->current->rra)++;
			tmp = tmp->prev;
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

void	set_sum(t_counters *cntrs, t_pointers *pntrs, int *ar, int part)
{
	int	i;
	int	j;

	if (part == pntrs->current->part)
	{
		set_b(pntrs, cntrs);
		i = find_pos(ar, pntrs->current->data);
		j = 1;
		while (1)
		{
			if (i + j == cntrs->counter_a + cntrs->counter_b)
			{
				i = 0;
				j = 0;
				break ;
			}
			if (is_contain(pntrs->a_first, cntrs->counter_a, ar[i + j]))
				break ;
			j++;
		}
		set_a(pntrs, cntrs, ar[i + j]);
		optimization(pntrs->current);
	}
}
