/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:37:21 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 19:06:53 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int    push_piv_min(t_stack *a, t_stack *b)
{
    int	n;

    if (find_min_piv(a) == -1)
        return (-1);
    if (find_min_piv(a) <= find_min_piv_bot(a))
		{
			n = find_min_piv(a);
			while (n-- > 0)
			{
				if (trier_b(b) == 2)
					oper("rr", a, b);
				else
					oper("ra", a, b);
			}
			oper("pb", a, b);
			sort_b(a,b);
		}
	else
		{
			n = find_min_piv_bot(a);
			while (n-- > 0)
			{
				if (trier_b(b) == 1)
					oper("rrr", a, b);
				else
				oper("rra", a, b);
			}
			oper("pb", a, b);
			sort_b(a,b);
		}
    return (1);
}

int   push_piv_max(t_stack *a, t_stack *b)
{
    int	n;

    if (find_max_piv(b) == -1)
        return (-1);
    if (find_max_piv(b) <= find_max_piv_bot(b))
		{
			n = find_max_piv(b);
			while (n-- > 0)
			{
				if (trier_a(a) == 2)
					oper("rr", a, b);
				else
					oper("rb", a, b);
			}
			oper("pa", a, b);
			sort_a(a,b);
		}
		else
		{
			n = find_max_piv_bot(b);
			while (n-- >= 0)
			{
				if (trier_a(a) == 1)
					oper("rrr", a, b);
				else
					oper("rrb", a, b);
			}
			oper("pa", a, b);
			sort_a(a,b);
		}
    return (1);
}


void	push_swap(t_stack *a, t_stack *b)
{
	while (a->size > 0)
		push_min_a(a, b);
	// rev_sort_5(a, b);
	while (b->size > 0)
		oper("pa", a, b);
}

void	push_swap_piv(t_stack *a, t_stack *b)
{
	while (1)
	{
		find_piv(a);
		while (a->size > 3)
		{
			if (push_piv_min(a, b) == -1)// il nya pas de nro dessous le piv
				find_piv(a);
		}
		while (a->size > 0)
		{
			push_min_a_simple(a,b);
		}
		// sort_5(a, b);
		// print_stack(a, 'a');
			// print_stack(b, 'b');
		find_piv(b);
		while (b->size > 3)
		{
			push_piv_max(a,b);
			if (push_piv_max(a, b) == -1)
				find_piv(b);
		}
		while (b->size > 0)
		{
			push_max_b_simple(a,b);
		}
			// print_stack(a, 'a');
			// print_stack(b, 'b');
		
		if (is_sorted(a->top) == 1)
			break;
	}
}
		// print_stack(a, 'a');
		// print_stack(b, 'b');