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
#endif //PUSH_SWAP_PUSH_SWAP_H
