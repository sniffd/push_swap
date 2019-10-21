/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:12 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:32:12 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pointers *pntrs, int flag)
{
	if (pntrs->a_first)
	{
		pntrs->a_first = pntrs->a_first->prev;
		pntrs->a_last = pntrs->a_last->prev;
		if (flag)
			ft_printf("rra\n");
	}
}

void	rrb(t_pointers *pntrs, int flag)
{
	if (pntrs->b_first)
	{
		pntrs->b_first = pntrs->b_first->prev;
		pntrs->b_last = pntrs->b_last->prev;
		if (flag)
			ft_printf("rrb\n");
	}
}

void	rrr(t_pointers *pntrs, int flag)
{
	rra(pntrs, 0);
	rrb(pntrs, 0);
	if (flag)
		ft_printf("rrr\n");
}
