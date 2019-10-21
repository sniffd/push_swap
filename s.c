/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:17 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:32:17 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pointers *pntrs, int flag)
{
	ft_swap(&(pntrs->a_first->data), &(pntrs->a_first->next->data));
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_pointers *pntrs, int flag)
{
	ft_swap(&(pntrs->b_first->data), &(pntrs->b_first->next->data));
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_pointers *pntrs, int flag)
{
	sa(pntrs, 0);
	sb(pntrs, 0);
	if (flag)
		ft_printf("ss\n");
}
