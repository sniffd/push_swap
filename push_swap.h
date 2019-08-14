#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "ft_printf.h"

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void	ft_qsort(int *ar, int end);
int		atoi_push_swap(const char *str, int *f);
void	add_last(t_stack **first, t_stack **last, t_stack *e);
t_stack	*create_elem(int n);
#endif //PUSH_SWAP_PUSH_SWAP_H
