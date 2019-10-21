/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:31:59 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/21 05:31:59 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"

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
	t_stack	*current;
}				t_pointers;

void			ft_qsort(int *ar, int end);
int				atoi_push_swap(const char *str, int *f);
void			add_last(t_pointers *pntrs, t_stack *e);
t_stack			*create_elem(int n);
void			sa(t_pointers *pntrs, int flag);
void			sb(t_pointers *pntrs, int flag);
void			ss(t_pointers *pntrs, int flag);
void			ra(t_pointers *pntrs, int flag);
void			rb(t_pointers *pntrs, int flag);
void			rr(t_pointers *pntrs, int flag);
void			rra(t_pointers *pntrs, int flag);
void			rrb(t_pointers *pntrs, int flag);
void			rrr(t_pointers *pntrs, int flag);
void			pa(t_pointers *pntrs, int flag);
void			pb(t_pointers *pntrs, int flag);
int				find_steps(t_stack *first, int size, int n);
int				is_contain(t_stack *first, int size, int n);
int				find_pos(const int *ar, int n);
int				find_elem(t_stack *first, int part);
void			set_sum(t_counters *cntrs, t_pointers *pntrs, int *ar,
		int part);
void			reset(t_stack *current);
void			mark_up(t_pointers *pntrs, t_counters *cntrs, const int *ar);
void			presort(t_pointers *pntrs, t_counters *cntrs);
void			final_rotation(t_pointers *pntrs, t_counters *cntrs,
		const int *ar);
int				is_sort(t_stack *first, t_stack *last);
void			execute(t_pointers *pntrs, t_counters *cntrs);
void			set_op(t_pointers *pntrs, int *ar, t_counters *cntrs);
void			five(t_pointers *pntrs, t_counters *cntrs, int *ar);
void			free_all(t_pointers *pntrs, int *ar);
void			create_stack(t_pointers *pntrs, int *ar, int argc);
#endif
