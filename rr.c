#include "push_swap.h"

void	rra(t_pointers *pntrs, int flag)
{
	pntrs->a_first = pntrs->a_first->prev;
	pntrs->a_last = pntrs->a_last->prev;
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_pointers *pntrs, int flag)
{
	pntrs->b_first = pntrs->b_first->prev;
	pntrs->b_last = pntrs->b_last->prev;
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_pointers *pntrs)
{
	rra(pntrs, 0);
	rrb(pntrs, 0);
	ft_printf("rrr\n");
}
