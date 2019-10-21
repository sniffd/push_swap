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
