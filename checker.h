#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"

typedef	struct	s_flags
{
	int	c;
	int	v;
	int flags;
}				t_flags;

typedef	struct	s_color
{
	int	ar;
	int	ag;
	int	br;
	int	bg;
}				t_color;

void	print_stack(t_stack *f, t_stack *l, int r, int g);
void	free_all(t_pointers *pntrs, int *ar);

#endif
