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
	int				sum;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef	struct	s_counters
{
	int	f_counter;
	int	s_counter;
	int	t_counter;
	int counter_a;
	int counter_b;
	int tmp;
}				t_counters;

typedef	struct	s_pointers
{
	t_stack	*a_first;
	t_stack	*a_last;
	t_stack	*b_first;
	t_stack	*b_last;
}				t_pointers;

void	ft_qsort(int *ar, int end);
int		atoi_push_swap(const char *str, int *f);
void	add_last(t_pointers *pntrs, t_stack *e);
t_stack	*create_elem(int n);
void	sa(t_stack **a_start);
void	sb(t_stack **b_start);
void	ss(t_stack **a_start, t_stack **b_start);
void	ra(t_pointers *pntrs, int flag);
void	rb(t_pointers *pntrs, int flag);
void	rr(t_pointers *pntrs);
void	rra(t_pointers *pntrs, int flag);
void	rrb(t_pointers *pntrs, int flag);
void	rrr(t_pointers *pntrs);
void	pa(t_pointers *pntrs);
void	pb(t_pointers *pntrs);
#endif //PUSH_SWAP_PUSH_SWAP_H
