/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:30:46 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:30:46 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_steps(t_stack *first, int size, int n)
{
	int	s;

	s = 0;
	while (s <= size / 2)
	{
		if (n == first->data)
			return (s);
		first = first->next;
		s++;
	}
	return (-1);
}

int		is_contain(t_stack *first, int size, int n)
{
	int	s;

	s = 0;
	while (s != size)
	{
		if (n == first->data)
			return (1);
		first = first->next;
		s++;
	}
	return (0);
}

int		find_pos(const int *ar, int n)
{
	int	i;

	i = 0;
	while (ar[i] != n)
		i++;
	return (i);
}

int		find_elem(t_stack *first, int part)
{
	t_stack	*tmp;
	int		f;
	int		b;

	tmp = first;
	f = 0;
	b = 0;
	while (tmp->part != part)
	{
		tmp = tmp->next;
		f++;
	}
	tmp = first;
	while (tmp->part != part)
	{
		tmp = tmp->next;
		b--;
	}
	return (f <= -b ? f : b);
}
