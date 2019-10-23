/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:20 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/23 20:17:37 by fdaryn-h         ###   ########.fr       */
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
	cntrs->counter_a = argc;
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
	int		i;
	int		j;
	int		f;
	int		*ar;
	int		ac;
	char	*tmp;

	i = 1;
	j = 0;
	ac = count_args(argc, argv);
	if (!(ar = (int *)ft_memalloc(sizeof(int) * ac)))
		exit(0);
	while (i < argc)
	{
		f = 0;
		tmp = argv[i];
		while (tmp)
		{
			ar[j] = atoi_push_swap(&tmp, &f);
			if (*tmp == ' ')
			{
				tmp++;
				if (*tmp == '\0')
					return (free_ar(ar));
			}
			else if (*tmp == '\0')
			{
				j++;
				break ;
			}
			else if (!ft_isdigit(*tmp) || f)
				return (free_ar(ar));
			j++;
		}
		i++;
	}
	ft_qsort(ar, ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		if (ar[i] == ar[i + 1])
			return (free_ar(ar));
		i++;
	}
	free(ar);
	return (ac);
}

int		main(int argc, char **argv)
{
	int			*ar;
	int			i;
	int			j;
	int			ac;
	t_pointers	*pntrs;

	i = 1;
	j = 0;
	if ((ac = validation(argc, argv)))
	{
		if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
			exit(0);
		if (!(ar = (int *)ft_memalloc(sizeof(int) * ac)))
			exit(0);
		while (i < argc)
		{
			while (*(argv[i]))
			{
				ar[j] = atoi_push_swap(&(argv[i]), NULL);
				if (*(argv[i]) == ' ')
					(argv[i])++;
				j++;
			}
			i++;
		}
		create_stack(pntrs, ar, ac);
		ft_qsort(ar, ac - 1);
		push_swap(pntrs, ar, ac);
		free_all(pntrs, ar);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
