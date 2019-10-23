/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:30:38 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/23 23:57:41 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include "get_next_line.h"

typedef	struct	s_flags
{
	int	c;
	int	v;
	int flags;
	int	ac;
}				t_flags;

typedef	struct	s_color
{
	int	ar;
	int	ag;
	int	br;
	int	bg;
}				t_color;

void			print_stack(t_stack *f, t_stack *l, int r, int g);
void			checker(t_pointers *pntrs, t_flags *flags);
int				do_operations(char *line, t_pointers *pntrs, t_color *clr);
void			parse_flags(const char *str, t_flags *flags);
void			visual(t_flags *flags, t_pointers *pntrs, t_color *clr);
void			skip_flag(char **str);
void			allocs(t_pointers **pntrs, int **ar, t_flags *flag);
void			main_help(t_pointers *pntrs, t_flags *flag, int *ar, int c);

#endif
