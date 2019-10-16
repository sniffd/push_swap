#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "ft_printf.h"

typedef struct	s_stack
{
	int				data;
	int				part;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void	ft_qsort(int *ar, int end);
int		atoi_push_swap(const char *str, int *f);
void	add_last(t_stack **first, t_stack **last, t_stack *e);
t_stack	*create_elem(int n);
void	sa(t_stack **a_start);
void	sb(t_stack **b_start);
void	ss(t_stack **a_start, t_stack **b_start);
void	ra(t_stack **a_start, t_stack **a_finish);
void	rb(t_stack **b_start, t_stack **b_finish);
void	rr(t_stack **a_start, t_stack **a_finish, t_stack **b_start, t_stack **b_finish);
void	rra(t_stack **a_start, t_stack **a_finish);
void	rrb(t_stack **b_start, t_stack **b_finish);
void	rrr(t_stack **a_start, t_stack **a_finish, t_stack **b_start, t_stack **b_finish);
void	pa(t_stack **a_start, t_stack **b_start);
void	pb(t_stack **a_start, t_stack **b_start);
#endif //PUSH_SWAP_PUSH_SWAP_H
