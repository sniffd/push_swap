#include "push_swap.h"

void	ra(t_pointers *pntrs, int flag)
{
	pntrs->a_first = pntrs->a_first->next;
	pntrs->a_last = pntrs->a_last->next;
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_pointers *pntrs, int flag)
{
	pntrs->b_first = pntrs->b_first->next;
	pntrs->b_last = pntrs->b_last->next;
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_pointers *pntrs)
{
	ra(pntrs, 0);
	rb(pntrs, 0);
	ft_printf("rr\n");
}
