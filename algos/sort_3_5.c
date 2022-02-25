/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:15:14 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:23:23 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	if (find_min(a) == 0 && find_max(a) == 1)
	{
		oper("rra", a, b);
		oper("sa", a, b);
	}
	if (find_min(a) == 1 && find_max(a) == 2)
		oper("sa", a, b);
	if (find_min(a) == 2 && find_max(a) == 1)
		oper("rra", a, b);
	if (find_min(a) == 1 && find_max(a) == 0)
		oper("ra", a, b);
	if (find_min(a) == 2 && find_max(a) == 0)
	{
		oper("sa", a, b);
		oper("rra", a, b);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	push_min_a(a, b);
	push_min_a(a, b);
	sort_3(a, b);
	oper("pa", a, b);
	oper("pa", a, b);
}
