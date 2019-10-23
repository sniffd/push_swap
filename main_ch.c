/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:12 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/23 19:50:14 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	skip_flag(&(argv[1]));
	ac = count_args(argc, argv);
	if (!(ar = (int *)ft_memalloc(sizeof(int) * ac)))
		exit(0);
	while (i < argc)
	{
		f = 0;
		tmp = argv[i];
		while (tmp)
		{
			if (*tmp == '\0')
				break ;
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
	create_stack(pntrs, ar, c);
	ft_qsort(ar, c - 1);
	checker(pntrs, flag);
	free_all(pntrs, ar);
	free(flag);
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
	if ((flag->ac = validation(c, v)))
	{
		if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
			exit(0);
		if (!(ar = (int *)ft_memalloc(sizeof(int) * (flag->ac))))
			exit(0);
		while (++i < c - 1)
			while (v[i + 1] && *(v[i + 1]))
			{
				ar[j] = atoi_push_swap(&(v[i + 1]), NULL);
				if ((*(v[i + 1])) == ' ')
					(v[i + 1])++;
				j++;
			}
		main_help(pntrs, flag, ar, flag->ac);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
