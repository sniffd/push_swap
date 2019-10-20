#include "push_swap.h"

void	print_stack(t_stack *f, t_stack *l)
{
	t_stack *tmp;

	tmp = f;
	while (1)
	{
		ft_printf("%i\n", tmp->data);
		if (tmp == l)
			break ;
		tmp = tmp->next;
	}
	ft_printf("\n");
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
