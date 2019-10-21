/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:20 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 20:52:36 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_pointers *pntrs, int *ar, int argc)
{
	t_counters	*cntrs;

	if (is_sort(pntrs->a_first, pntrs->a_last))
		return ;
	if (!(cntrs = (t_counters *)ft_memalloc(sizeof(t_counters))))
		exit(0);
	cntrs->counter_a = argc - 1;
	if (cntrs->counter_a == 5 || cntrs->counter_a == 3)
		five(pntrs, cntrs, ar);
	else
	{
		mark_up(pntrs, cntrs, ar);
		presort(pntrs, cntrs);
		while (cntrs->counter_b)
		{
			set_op(pntrs, ar, cntrs);
			pntrs->b_last = pntrs->b_first->prev;
			execute(pntrs, cntrs);
			pa(pntrs, 1);
			(cntrs->counter_a)++;
			(cntrs->counter_b)--;
		}
		final_rotation(pntrs, cntrs, ar);
	}
	free(cntrs);
}

int		free_ar(void *ar)
{
	free(ar);
	return (0);
}

int		validation(int argc, char **argv)
{
	int	i;
	int	f;
	int *ar;

	i = 1;
	if (!(ar = (int *)ft_memalloc(sizeof(int) * (argc - 1))))
		exit(0);
	while (i < argc)
	{
		f = 0;
		ar[i - 1] = atoi_push_swap(argv[i], &f);
		if (f)
			return (free_ar(ar));
		i++;
	}
	ft_qsort(ar, argc - 2);
	i = 0;
	while (i < argc - 2)
	{
		if (ar[i] == ar[i + 1])
			return (free_ar(ar));
		i++;
	}
	free(ar);
	return (1);
}

int		main(int argc, char **argv)
{
	int			*ar;
	int			i;
	t_pointers	*pntrs;

	i = 1;
	if (validation(argc, argv))
	{
		if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
			exit(0);
		if (!(ar = (int *)ft_memalloc(sizeof(int) * (argc - 1))))
			exit(0);
		while (i < argc)
		{
			ar[i - 1] = ft_atoi(argv[i]);
			i++;
		}
		create_stack(pntrs, ar, argc);
		ft_qsort(ar, argc - 2);
		push_swap(pntrs, ar, argc);
		free_all(pntrs, ar);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
