/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:29:51 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 20:42:43 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	push(char *line, t_pointers *pntrs, t_color *clr)
{
	if (!(ft_strcmp(line, "pa")))
	{
		pa(pntrs, 0);
		clr->ag = 1;
		clr->br = 1;
		return (1);
	}
	else if (!(ft_strcmp(line, "pb")))
	{
		pb(pntrs, 0);
		clr->ar = 1;
		clr->bg = 1;
		return (1);
	}
	return (0);
}

int	rotate(char *line, t_pointers *pntrs, t_color *clr)
{
	if (!(ft_strcmp(line, "ra")))
	{
		ra(pntrs, 0);
		clr->ag = 2;
		clr->ar = 1;
		return (1);
	}
	else if (!(ft_strcmp(line, "rb")))
	{
		rb(pntrs, 0);
		clr->bg = 2;
		clr->br = 1;
		return (1);
	}
	else if (!(ft_strcmp(line, "rr")))
	{
		rr(pntrs, 0);
		clr->br = 1;
		clr->bg = 2;
		clr->ar = 1;
		clr->ag = 2;
		return (1);
	}
	return (0);
}

int	rev_rotate(char *line, t_pointers *pntrs, t_color *clr)
{
	if (!(ft_strcmp(line, "rra")))
	{
		rra(pntrs, 0);
		clr->ag = 1;
		clr->ar = 2;
		return (1);
	}
	else if (!(ft_strcmp(line, "rrb")))
	{
		rrb(pntrs, 0);
		clr->bg = 1;
		clr->br = 2;
		return (1);
	}
	else if (!(ft_strcmp(line, "rrr")))
	{
		rrr(pntrs, 0);
		clr->br = 2;
		clr->bg = 1;
		clr->ar = 2;
		clr->ag = 1;
		return (1);
	}
	return (0);
}

int	sswap(char *line, t_pointers *pntrs, t_color *clr)
{
	if (!(ft_strcmp(line, "sa")))
	{
		sa(pntrs, 0);
		clr->ag = 3;
		return (1);
	}
	else if (!(ft_strcmp(line, "sb")))
	{
		sb(pntrs, 0);
		clr->bg = 3;
		return (1);
	}
	else if (!(ft_strcmp(line, "ss")))
	{
		ss(pntrs, 0);
		clr->ag = 3;
		clr->bg = 3;
		return (1);
	}
	return (0);
}

int	do_operations(char *line, t_pointers *pntrs, t_color *clr)
{
	if (push(line, pntrs, clr) || rotate(line, pntrs, clr) ||
		rev_rotate(line, pntrs, clr) || sswap(line, pntrs, clr))
		;
	else
	{
		write(2, "Error\n", 6);
		free(line);
		free(clr);
		return (1);
	}
	return (0);
}
