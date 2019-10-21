/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:47 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:32:47 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_flags(const char *str, t_flags *flags)
{
	while (*str)
	{
		if (*str == 'v')
			flags->v = 1;
		else if (*str == 'c')
			flags->c = 1;
		str++;
	}
}

void	visual(t_flags *flags, t_pointers *pntrs, t_color *clr)
{
	if (flags->v)
	{
		ft_printf("A: ");
		if (flags->c)
			print_stack(pntrs->a_first, pntrs->a_last, clr->ar, clr->ag);
		else
			print_stack(pntrs->a_first, pntrs->a_last, 0, 0);
		ft_printf("B: ");
		if (flags->c)
			print_stack(pntrs->b_first, pntrs->b_last, clr->br, clr->bg);
		else
			print_stack(pntrs->b_first, pntrs->b_last, 0, 0);
	}
}
