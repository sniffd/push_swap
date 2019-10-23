/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:12 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/24 00:03:06 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		parse_cycle(char *tmp, int *ar, int *j, int *f)
{
	while (tmp)
	{
		if (*tmp == '\0')
			break ;
		ar[*j] = atoi_push_swap(&tmp, f);
		if (*tmp == ' ' && !*f)
		{
			tmp++;
			if (*tmp == '\0')
				return (free_ar(ar));
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
	skip_flag(&(argv[1]));
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

void	checker(t_pointers *pntrs, t_flags *flags)
{
	char	*line;
	t_color	*clr;

	line = NULL;
	if (!(clr = (t_color *)ft_memalloc(sizeof(t_color))))
		exit(0);
	while (get_next_line(0, &line) > 0)
	{
		clr->ag = 0;
		clr->ar = 0;
		clr->bg = 0;
		clr->br = 0;
		if (do_operations(line, pntrs, clr))
			return ;
		visual(flags, pntrs, clr);
		free(line);
	}
	free(clr);
	if (pntrs->b_first == NULL && is_sort(pntrs->a_first, pntrs->a_last))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	set_ar(int i, char **v, int *j, int *ar)
{
	while (v[i + 1] && *(v[i + 1]))
	{
		ar[*j] = atoi_push_swap(&(v[i + 1]), NULL);
		if ((*(v[i + 1])) == ' ')
			(v[i + 1])++;
		(*j)++;
	}
}

int		main(int c, char **v)
{
	int			*ar;
	int			i;
	int			j;
	t_flags		*flag;
	t_pointers	*pntrs;

	i = 1;
	j = 0;
	if (c == 1 || !(flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		exit(0);
	if (c > i && v[i][0] == '-' && v[i][1] == 'v')
		parse_flags(v[i++], flag);
	skip_flag(&(v[1]));
	i = -1;
	if ((flag->ac = validation(c, v, 0)))
	{
		allocs(&pntrs, &ar, flag);
		while (++i < c - 1)
			set_ar(i, v, &j, ar);
		main_help(pntrs, flag, ar, flag->ac);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
