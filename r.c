#include "push_swap.h"

void	ra(t_stack **a_start, t_stack **a_finish)
{
	*a_start = (*a_start)->next;
	*a_finish = (*a_finish)->next;
}

void	rb(t_stack **b_start, t_stack **b_finish)
{
	*b_start = (*b_start)->next;
	*b_finish = (*b_finish)->next;
}

void	rr(t_stack **a_start, t_stack **a_finish, t_stack **b_start, t_stack **b_finish)
{
	ra(a_start, a_finish);
	rb(b_start, b_finish);
}
