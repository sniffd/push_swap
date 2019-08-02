#include "push_swap.h"

void	pa(t_stack **a_start, t_stack **b_start)//TODO сделать обработку случаев пустого стэка и стека из одного элемента;
{
	if (*b_start)
	{
		(*a_start)->prev->next = *b_start;
		(*b_start)->prev->next = (*b_start)->next;
		(*b_start)->next = *a_start;
		(*b_start)->prev->next->prev = (*b_start)->prev;
		(*b_start)->prev = (*a_start)->prev;
		(*a_start)->prev = *b_start;
		*a_start = (*a_start)->prev;
	}
}

void	pb(t_stack **a_start, t_stack **b_start)
{
	if (*a_start)
	{
		(*b_start)->prev->next = *a_start;
		(*a_start)->prev->next = (*a_start)->next;
		(*a_start)->next = *b_start;
		(*a_start)->prev->next->prev = (*a_start)->prev;
		(*a_start)->prev = (*b_start)->prev;
		(*b_start)->prev = *a_start;
		*b_start = (*b_start)->prev;
	}
}
