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

void	create_stack(t_pointers *pntrs, int *ar, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_last(pntrs, create_elem(ar[i - 1]));
		i++;
	}
}

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
		if (!(ft_strcmp(line, "pa")))
		{
			pa(pntrs, 0);
			clr->ag = 1;
			clr->br = 1;
		}
		else if (!(ft_strcmp(line, "pb")))
		{
			pb(pntrs, 0);
			clr->ar = 1;
			clr->bg = 1;
		}
		else if (!(ft_strcmp(line, "ra")))
		{
			ra(pntrs, 0);
			clr->ag = 2;
			clr->ar = 1;
		}
		else if (!(ft_strcmp(line, "rb")))
		{
			rb(pntrs, 0);
			clr->bg = 2;
			clr->br = 1;
		}
		else if (!(ft_strcmp(line, "rr")))
		{
			rr(pntrs, 0);
			clr->br = 1;
			clr->bg = 2;
			clr->ar = 1;
			clr->ag = 2;
		}
		else if (!(ft_strcmp(line, "rra")))
		{
			rra(pntrs, 0);
			clr->ag = 1;
			clr->ar = 2;
		}
		else if (!(ft_strcmp(line, "rrb")))
		{
			rrb(pntrs, 0);
			clr->bg = 1;
			clr->br = 2;
		}
		else if (!(ft_strcmp(line, "rrr")))
		{
			rrr(pntrs, 0);
			clr->br = 2;
			clr->bg = 1;
			clr->ar = 2;
			clr->ag = 1;
		}
		else if (!(ft_strcmp(line, "sa")))
		{
			sa(pntrs, 0);
			clr->ag = 3;
		}
		else if (!(ft_strcmp(line, "sb")))
		{
			sb(pntrs, 0);
			clr->bg = 3;
		}
		else if (!(ft_strcmp(line, "ss")))
		{
			ss(pntrs, 0);
			clr->ag = 3;
			clr->bg = 3;
		}
		else
		{
			write(2, "Error\n", 6);
			free(line);
			free(clr);
			return ;
		}
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
		free(line);
	}
	free(clr);
	if (pntrs->b_first == NULL && is_sort(pntrs->a_first, pntrs->a_last))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	int			*ar;
	int			i;
	t_flags		*flag;
	t_pointers	*pntrs;

	i = 1;
	if (argc == 1 || !(flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		exit(0);
	while (argc > 1 && argv[i][0] == '-' && argv[i][1] != '\0' && !ft_isdigit(argv[i][1]))
		parse_flags(argv[i++], flag);
	flag->flags = i ? i - 1 : 0;
	if (!(pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
		exit(0);
	i = 0;
	if (validation(argc - flag->flags , argv + flag->flags))
	{
		if (!(ar = (int *)ft_memalloc(sizeof(int) * (argc - flag->flags - 1))))
			exit(0);
		while (flag->flags + i < argc - 1)
		{
			ar[i] = ft_atoi(argv[flag->flags + i + 1]);
			i++;
		}
		create_stack(pntrs, ar, argc - flag->flags);
		ft_qsort(ar, argc - 2 - flag->flags);
		checker(pntrs, flag);
		free_all(pntrs, ar);
		free(flag);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}