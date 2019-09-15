#include "push_swap.h"

void	pa(t_stack **a_start, t_stack **b_start)//TODO сделать обработку случаев пустого стэка и стека из одного элемента;
{
	if (*b_start)
	{
		if (*a_start)
		{
			(*a_start)->prev->next = *b_start;
			(*b_start)->prev->next = (*b_start)->next;
			(*b_start)->next->prev = (*b_start)->prev;
			(*b_start)->prev = (*a_start)->prev;
			*b_start = (*b_start)->next;
			(*a_start)->prev->next->next = *a_start;
			(*a_start)->prev = (*a_start)->prev->next;
			*a_start = (*a_start)->prev;
		}
		else
		{
			*a_start = *b_start;
			*b_start = (*b_start)->next;
			(*a_start)->prev->next = *b_start;
			(*b_start)->prev = (*a_start)->prev;
			(*a_start)->prev = *a_start;
			(*a_start)->next = *a_start;
		}
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a_start, t_stack **b_start)
{
	if (*a_start)
	{
		if (*b_start)
		{
			(*b_start)->prev->next = *a_start;
			(*a_start)->prev->next = (*a_start)->next;
			(*a_start)->next->prev = (*a_start)->prev;
			(*a_start)->prev = (*b_start)->prev;
			*a_start = (*a_start)->next;
			(*b_start)->prev->next->next = *b_start;
			(*b_start)->prev = (*b_start)->prev->next;
			*b_start = (*b_start)->prev;
		}
		else
		{
			*b_start = *a_start;
			*a_start = (*a_start)->next;
			(*b_start)->prev->next = *a_start;
			(*a_start)->prev = (*b_start)->prev;
			(*b_start)->prev = *b_start;
			(*b_start)->next = *b_start;
		}
	}
	ft_printf("pb\n");
}
