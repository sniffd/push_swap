/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:30 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:31:30 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_several(t_pointers *pntrs)
{
	if (pntrs->a_first)
	{
		pntrs->a_first->prev->next = pntrs->b_first;
		(pntrs->b_first)->prev->next = (pntrs->b_first)->next;
		(pntrs->b_first)->next->prev = (pntrs->b_first)->prev;
		(pntrs->b_first)->prev = pntrs->a_first->prev;
		pntrs->b_first = (pntrs->b_first)->next;
		pntrs->a_first->prev->next->next = pntrs->a_first;
		pntrs->a_first->prev = pntrs->a_first->prev->next;
		pntrs->a_first = pntrs->a_first->prev;
	}
	else
	{
		pntrs->a_first = pntrs->b_first;
		pntrs->b_first = (pntrs->b_first)->next;
		pntrs->a_first->prev->next = pntrs->b_first;
		(pntrs->b_first)->prev = pntrs->a_first->prev;
		pntrs->a_first->prev = pntrs->a_first;
		pntrs->a_first->next = pntrs->a_first;
	}
	pntrs->a_last = pntrs->a_first->prev;
	pntrs->b_last = (pntrs->b_first) ? pntrs->b_first->prev : NULL;
}

void	pa(t_pointers *pntrs, int flag)
{
	if (pntrs->b_first)
	{
		if (pntrs->b_first == pntrs->b_last)
		{
			if (pntrs->a_first)
			{
				pntrs->a_last->next = pntrs->b_first;
				pntrs->b_first->next = pntrs->a_first;
				pntrs->a_first->prev = pntrs->b_first;
				pntrs->b_first->prev = pntrs->a_last;
				pntrs->a_first = pntrs->a_first->prev;
			}
			else
			{
				pntrs->a_first = pntrs->b_first;
				pntrs->a_last = pntrs->b_last;
			}
			pntrs->b_first = NULL;
			pntrs->b_last = NULL;
		}
		else
			pa_several(pntrs);
		if (flag)
			ft_printf("pa\n");
	}
}

void	pb_several(t_pointers *pntrs)
{
	if (pntrs->b_first)
	{
		pntrs->b_first->prev->next = pntrs->a_first;
		pntrs->a_first->prev->next = pntrs->a_first->next;
		pntrs->a_first->next->prev = pntrs->a_first->prev;
		pntrs->a_first->prev = pntrs->b_first->prev;
		pntrs->a_first = pntrs->a_first->next;
		pntrs->b_first->prev->next->next = pntrs->b_first;
		pntrs->b_first->prev = pntrs->b_first->prev->next;
		pntrs->b_first = pntrs->b_first->prev;
	}
	else
	{
		pntrs->b_first = pntrs->a_first;
		pntrs->a_first = pntrs->a_first->next;
		pntrs->b_first->prev->next = pntrs->a_first;
		pntrs->a_first->prev = pntrs->b_first->prev;
		pntrs->b_first->prev = pntrs->b_first;
		pntrs->b_first->next = pntrs->b_first;
	}
	pntrs->b_last = pntrs->b_first->prev;
	pntrs->a_last = (pntrs->a_first) ? pntrs->a_first->prev : NULL;
}

void	pb(t_pointers *pntrs, int flag)
{
	if (pntrs->a_first)
	{
		if (pntrs->a_first == pntrs->a_last)
		{
			if (pntrs->b_first)
			{
				pntrs->b_last->next = pntrs->a_first;
				pntrs->a_first->next = pntrs->b_first;
				pntrs->b_first->prev = pntrs->a_first;
				pntrs->a_first->prev = pntrs->b_last;
				pntrs->b_first = pntrs->b_first->prev;
			}
			else
			{
				pntrs->b_first = pntrs->a_first;
				pntrs->b_last = pntrs->a_last;
			}
			pntrs->a_first = NULL;
			pntrs->a_last = NULL;
		}
		else
			pb_several(pntrs);
		if (flag)
			ft_printf("pb\n");
	}
}
