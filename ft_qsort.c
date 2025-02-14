/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:01 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:31:01 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_median(int *ar, int end)
{
	if (ar[end / 2] < ar[0])
		ft_swap(ar, ar + (end / 2));
	if (ar[end] < ar[0])
		ft_swap(ar, ar + end);
	if (ar[end / 2] > ar[end])
		ft_swap(ar + end, ar + end / 2);
}

int		partition(int *ar, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	index;

	get_median(ar, end);
	index = end / 2;
	pivot = ar[index];
	i = -1;
	j = end + 1;
	while ((i++ || 1) && (j-- || 1))
	{
		while (ar[i] < pivot && i < end)
			i = i + 1;
		while (ar[j] > pivot && j > 0)
			j = j - 1;
		if (i >= j)
			return (index);
		ft_swap(ar + i, ar + j);
		if (i == index)
			index = j++;
		else if (j == index)
			index = i--;
	}
}

void	ft_qsort(int *ar, int end)
{
	int	p;

	if (end > 0)
	{
		p = partition(ar, end);
		ft_qsort(ar, p - 1);
		ft_qsort(ar + p + 1, end - p - 1);
	}
}
