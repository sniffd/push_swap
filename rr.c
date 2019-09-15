#include "push_swap.h"

void	rra(t_stack **a_start, t_stack **a_finish)
{
	*a_start = (*a_start)->prev;
	*a_finish = (*a_start)->prev;
	ft_printf("rra\n");
}

void	rrb(t_stack **b_start, t_stack **b_finish)
{
	*b_start = (*b_start)->prev;
	*b_finish = (*b_start)->prev;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a_start, t_stack **a_finish, t_stack **b_start, t_stack **b_finish)
{
	rra(a_start, a_finish);
	rrb(b_start, b_finish);
}
