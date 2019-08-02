#include "push_swap.h"

void	sa(t_stack **a_start)
{
	ft_swap(&(*a_start)->data, &(*a_start)->next->data);
}

void	sb(t_stack **b_start)
{
	ft_swap(&(*b_start)->data, &(*b_start)->next->data);
}

void	ss(t_stack **a_start, t_stack **b_start)
{
	sa(a_start);
	sb(b_start);
}
