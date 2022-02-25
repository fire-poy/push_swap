/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:37:21 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:29:28 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_min_a(t_stack *a, t_stack *b)
{
	int	n;

	if (find_min(a) <= find_min_bot(a))
	{
		n = find_min(a);
		while (n-- > 0)
			oper("ra", a, b);
		oper("pb", a, b);
	}
	else
	{
		n = find_min_bot(a);
		while (n-- >= 0)
			oper("rra", a, b);
		oper("pb", a, b);
	}
}

void	push_max_b(t_stack *a, t_stack *b)
{
	int	n;

	if (find_max(b) <= find_max_bot(b))
	{
		n = find_max(b);
		while (n-- > 0)
			oper("rb", a, b);
		oper("pa", a, b);
	}
	else
	{
		n = find_max_bot(b);
		while (n-- >= 0)
			oper("rrb", a, b);
		oper("pa", a, b);
	}
}

int	push_sous_piv(t_stack *a, t_stack *b, t_ch *c)
{
	if (find_sous_piv(a) == -1)
		return (-1);
	else
	{
		choix(a, b, c);
		oper("pb", a, b);
		if (b->size >= 2)
		{
			if (b->top->value < b->top->next->value)
				oper("sb", a, b);
		}
	}
	return (1);
}

void	push_swap_piv(t_stack *a, t_stack *b, t_ch *c)
{
	find_piv(a);
	while (a->size > 0)
	{
		if (push_sous_piv(a, b, c) == -1)
			find_piv(a);
	}
	while (b->size > 0)
		push_max_b(a, b);
}
