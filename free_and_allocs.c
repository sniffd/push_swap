/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_allocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:04:43 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/24 00:04:43 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		free_ar(void *ar)
{
	free(ar);
	return (0);
}

void	allocs(t_pointers **pntrs, int **ar, t_flags *flag)
{
	if (!(*pntrs = (t_pointers *)ft_memalloc(sizeof(t_pointers))))
		exit(0);
	if (!(*ar = (int *)ft_memalloc(sizeof(int) * (flag->ac))))
		exit(0);
}
