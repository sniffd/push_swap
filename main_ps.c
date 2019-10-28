/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:20 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/25 18:06:31 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Desktop/fdaryn-h/push_swap.h"

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

int		parse_cycle(char *tmp, int *ar, int *j, int *f)
{
	while (tmp)
	{
		ar[*j] = atoi_push_swap(&tmp, f);
		if (*tmp == ' ' && !*f)
		{
			tmp++;
			if (*tmp == '\0')
				return (free_ar(ar
		}
		else if (*tmp == '\0' && !*f && ((*j)++ || 1))
			break ;
		else if (!ft_isdigit(*tmp) || *f)
			return (free_ar(ar));
		(*j)++;
	}
	return (1);
}

int		validation(int argc, char **argv, int ac)
{
	int		i;
	int		j;
	int		f;
	int		*ar;

	i = 0;
	j = 0;
	ac = count_args(argc, argv);
	if (!(ar = (int *)ft_memalloc(sizeof(int) * ac)))
		exit(0);
	f = 0;
	while (++i < argc)
		if (!parse_cycle(argv[i], ar, &j, &f))
			return (0);
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

void	set_ar(char **argv, int i, int *j, int *ar)
{
	while (*(argv[i]))
	{
		ar[*j] = atoi_push_swap(&(argv[i]), NULL);
		if (*(argv[i]) == ' ')
			(argv[i])++;
		(*j)++;
	}
}

int		main(int argc, char **argv)
{
	int			*ar;
	int			i;
	int			j;
	int			ac;
	t_pointers	*pntrs;

	i = 0;
	j = 0;
	if ((ac = validation(argc, argv, 0)))
	{
		if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
			exit(0);
		if (!(ar = (int *)ft_memalloc(sizeof(int) * ac)))
			exit(0);
		while (++i < argc)
			set_ar(argv, i, &j, ar);
		create_stack(pntrs, ar, ac);
		ft_qsort(ar, ac - 1);
		push_swap(pntrs, ar, ac);
		free_all(pntrs, ar);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
