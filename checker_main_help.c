/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:04:52 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/10/24 00:04:52 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	main_help(t_pointers *pntrs, t_flags *flag, int *ar, int c)
{
	create_stack(pntrs, ar, c);
	ft_qsort(ar, c - 1);
	checker(pntrs, flag);
	free_all(pntrs, ar);
	free(flag);
}
