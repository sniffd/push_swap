/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   services.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:32:24 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/23 19:39:17 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *f, t_stack *l, int r, int g)
{
	t_stack *tmp;

	tmp = f;
	if (tmp)
	{
		while (1)
		{
			if ((tmp == f && r == 1) || (tmp == l && r == 2))
				ft_printf("\x1b[0;31;10m%i \x1b[0m", tmp->data);
			else if ((tmp == f && (g == 1 || g == 3)) ||
			(tmp == f->next && g == 3) || (tmp == l && g == 2))
				ft_printf("\x1b[0;32;10m%i \x1b[0m", tmp->data);
			else
				ft_printf("%i ", tmp->data);
			if (tmp == l)
				break ;
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

int		is_sort(t_stack *first, t_stack *last)
{
	t_stack	*current;

	current = first;
	while (current != last)
	{
		if (current->next->data < current->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	create_stack(t_pointers *pntrs, int *ar, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		add_last(pntrs, create_elem(ar[i]));
		i++;
	}
}

void	skip_flag(char **str)
{
	if (**str == '-' && ft_isalpha((*str)[1]))
		(*str)++;
	while (ft_isalpha(**str))
		(*str)++;
	if (**str == ' ' && ((*str)[1]))
		(*str)++;
}

int		count_args(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		res;

	res = 1;
	i = 1;
	while (i < argc)
	{
		tmp = argv[i];
		if (*tmp == ' ')
			return (0);
		if (*tmp == '\0')
			res--;
		while (*tmp && (ft_isdigit(*tmp) || *tmp == ' ' || *tmp == '-' || *tmp == '+'))
		{
			if (*tmp == ' ')
				res++;
			tmp++;
		}
		if (*tmp)
			return (0);
		i++;
		res++;
	}
	res--;
	return (res);
}

void	free_all(t_pointers *pntrs, int *ar)
{
	t_stack *tmp;
	t_stack *temp;

	free(ar);
	tmp = pntrs->a_first;
	if (tmp)
	{
		while (tmp != pntrs->a_last && ((temp = tmp->next) || 1))
		{
			free(tmp);
			tmp = temp;
		}
		free(tmp);
	}
	tmp = pntrs->b_first;
	if (tmp)
	{
		while (tmp != pntrs->b_last && ((temp = tmp->next) || 1))
		{
			free(tmp);
			tmp = temp;
		}
		free(tmp);
	}
	free(pntrs);
}
