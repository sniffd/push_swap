#include "push_swap.h"

void	pa(t_pointers *pntrs)//TODO сделать обработку стека из одного элемента;
{
	if (pntrs->b_first)
	{
		if (pntrs->a_first)
		{
			pntrs->a_first->prev->next = pntrs->b_first;
			(pntrs->b_first)->prev->next = (pntrs->b_first)->next;
			(pntrs->b_first)->next->prev = (pntrs->b_first)->prev;
			(pntrs->b_first)->prev = pntrs->a_first->prev;
			pntrs->b_first = (pntrs->b_first)->next;
			pntrs->a_first->prev->next->next = pntrs->a_first;
			pntrs->a_first->prev = pntrs->a_first->prev->next;
			pntrs->a_first = pntrs->a_first->prev;
		}
		else
		{
			pntrs->a_first = pntrs->b_first;
			pntrs->b_first = (pntrs->b_first)->next;
			pntrs->a_first->prev->next = pntrs->b_first;
			(pntrs->b_first)->prev = pntrs->a_first->prev;
			pntrs->a_first->prev = pntrs->a_first;
			pntrs->a_first->next = pntrs->a_first;
		}
		pntrs->a_last = pntrs->a_first->prev;
		pntrs->b_last = (pntrs->b_first) ? pntrs->b_first->prev : NULL;
		ft_printf("pa\n");
	}
}

void	pb(t_pointers *pntrs)
{
	if (pntrs->a_first)
	{
		if (pntrs->b_first)
		{
			pntrs->b_first->prev->next = pntrs->a_first;
			pntrs->a_first->prev->next = pntrs->a_first->next;
			pntrs->a_first->next->prev = pntrs->a_first->prev;
			pntrs->a_first->prev = pntrs->b_first->prev;
			pntrs->a_first = pntrs->a_first->next;
			pntrs->b_first->prev->next->next = pntrs->b_first;
			pntrs->b_first->prev = pntrs->b_first->prev->next;
			pntrs->b_first = pntrs->b_first->prev;
		}
		else
		{
			pntrs->b_first = pntrs->a_first;
			pntrs->a_first = pntrs->a_first->next;
			pntrs->b_first->prev->next = pntrs->a_first;
			pntrs->a_first->prev = pntrs->b_first->prev;
			pntrs->b_first->prev = pntrs->b_first;
			pntrs->b_first->next = pntrs->b_first;
		}
		pntrs->b_last = pntrs->b_first->prev;
		pntrs->a_last = (pntrs->a_first) ? pntrs->a_first->prev : NULL;
		ft_printf("pb\n");
	}
}
