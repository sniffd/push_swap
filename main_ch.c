/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:12 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 21:08:37 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (f || !(ft_strcmp(argv[i], "+")) || !(ft_strcmp(argv[i], "-")))
			return (0);
		i++;
	}
	ft_qsort(ar, argc - 2);
	i = 0;
	while (i < argc - 2)
	{
		if (ar[i] == ar[i + 1])
			return (0);
		i++;
	}
	free(ar);
	return (1);
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

void	main_help(t_pointers *pntrs, t_flags *flag, int *ar, int c)
{
	create_stack(pntrs, ar, c - flag->flags);
	ft_qsort(ar, c - 2 - flag->flags);
	checker(pntrs, flag);
	free_all(pntrs, ar);
	free(flag);
}

int		main(int c, char **v)
{
	int			*ar;
	int			i;
	t_flags		*flag;
	t_pointers	*pntrs;

	i = 1;
	if (c == 1 || !(flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		exit(0);
	while (c > i && v[i][0] == '-' && v[i][1] != '\0' && !ft_isdigit(v[i][1]))
		parse_flags(v[i++], flag);
	flag->flags = i ? i - 1 : 0;
	i = -1;
	if (validation(c - flag->flags, v + flag->flags))
	{
		if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
			exit(0);
		if (!(ar = (int *)ft_memalloc(sizeof(int) * (c - flag->flags - 1))))
			exit(0);
		while (flag->flags + ++i < c - 1)
			ar[i] = ft_atoi(v[flag->flags + i + 1]);
		main_help(pntrs, flag, ar, c);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
