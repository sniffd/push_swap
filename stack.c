#include "push_swap.h"

t_stack	*create_elem(int n)
{
	t_stack	*e = (t_stack *)ft_memalloc(sizeof(t_stack));
	e->data = n;
	return (e);
}
void	add_last(t_stack **first, t_stack **last, t_stack *e)
{
	if (!*last)
	{
		*last = e;
		*first = e;
		e->next = e;
		e->prev = e;
	}
	else
	{
		(*last)->prev = e;
		e->next = (*last);
		e->prev = (*first);
		(*first)->next = e;
		(*last) = e;
	}
}