/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:05 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:32:05 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pointers *pntrs, int flag)
{
	if (pntrs->a_first)
	{
		pntrs->a_first = pntrs->a_first->next;
		pntrs->a_last = pntrs->a_last->next;
		if (flag)
			ft_printf("ra\n");
	}
}

void	rb(t_pointers *pntrs, int flag)
{
	if (pntrs->b_first)
	{
		pntrs->b_first = pntrs->b_first->next;
		pntrs->b_last = pntrs->b_last->next;
		if (flag)
			ft_printf("rb\n");
	}
}

void	rr(t_pointers *pntrs, int flag)
{
	ra(pntrs, 0);
	rb(pntrs, 0);
	if (flag)
		ft_printf("rr\n");
}
