#include "push_swap.h"

t_stack	*create_elem(int n)
{
	t_stack	*e = (t_stack *)ft_memalloc(sizeof(t_stack));
	e->data = n;
	return (e);
}
void	add_last(t_pointers *pntrs, t_stack *e)
{
	if (!(pntrs->a_last))
	{
		pntrs->a_last = e;
		pntrs->a_first = e;
		e->next = e;
		e->prev = e;
	}
	else
	{
		e->next = pntrs->a_first;
		pntrs->a_last->next = e;
		e->prev = pntrs->a_last;
		pntrs->a_first->prev = e;
		pntrs->a_last = e;
	}
}