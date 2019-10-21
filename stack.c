/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:41 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 06:43:32 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_elem(int n)
{
	t_stack *e;

	e = (t_stack *)ft_memalloc(sizeof(t_stack));
	e->data = n;
	return (e);
}

void	add_last(t_pointers *pntrs, t_stack *e)
{
	if (!(pntrs->a_last))
	{
		pntrs->a_last = e;
		pntrs->a_first = e;
		e->next = e;
		e->prev = e;
	}
	else
	{
		e->next = pntrs->a_first;
		pntrs->a_last->next = e;
		e->prev = pntrs->a_last;
		pntrs->a_first->prev = e;
		pntrs->a_last = e;
	}
}
