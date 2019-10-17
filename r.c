#include "push_swap.h"

void	ra(t_stack **a_start, t_stack **a_finish, int flag)
{
	*a_start = (*a_start)->next;
	*a_finish = (*a_finish)->next;
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack **b_start, t_stack **b_finish, int flag)
{
	*b_start = (*b_start)->next;
	*b_finish = (*b_finish)->next;
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_stack **a_start, t_stack **a_finish, t_stack **b_start, t_stack **b_finish)
{
	ra(a_start, a_finish, 0);
	rb(b_start, b_finish, 0);
	ft_printf("rr\n");
}
