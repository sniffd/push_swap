/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:30:53 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:30:53 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_pointers *pntrs)
{
	int	a;
	int	b;
	int	c;

	a = pntrs->a_first->data;
	b = pntrs->a_first->next->data;
	c = pntrs->a_last->data;
	if (c > a && a > b)
		sa(pntrs, 1);
	else if (a > b && b > c)
	{
		sa(pntrs, 1);
		rra(pntrs, 1);
	}
	else if (a > c && c > b)
		ra(pntrs, 1);
	else if (b > c && c > a)
	{
		sa(pntrs, 1);
		ra(pntrs, 1);
	}
	else
		rra(pntrs, 1);
}

void	five(t_pointers *pntrs, t_counters *cntrs, int *ar)
{
	if (cntrs->counter_a == 3)
		three(pntrs);
	else
	{
		pntrs->current = pntrs->a_first;
		while (pntrs->current->part != 1 && (pntrs->current->part = 1))
			pntrs->current = pntrs->current->next;
		cntrs->f_counter = 5;
		if (pntrs->a_first->data == ar[0] || pntrs->a_first->data == ar[4])
			ra(pntrs, 1);
		pb(pntrs, 1);
		if (pntrs->a_first->data == ar[0] || pntrs->a_first->data == ar[4])
			ra(pntrs, 1);
		pb(pntrs, 1);
		three(pntrs);
		set_op(pntrs, ar, cntrs);
		execute(pntrs, cntrs);
		pa(pntrs, 1);
		set_op(pntrs, ar, cntrs);
		execute(pntrs, cntrs);
		pa(pntrs, 1);
		final_rotation(pntrs, cntrs, ar);
	}
}
