/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:15:08 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 18:08:30 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    push_min_a_simple(t_stack *a, t_stack *b)
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

void    push_min_a(t_stack *a, t_stack *b)
{
    int	n;

    if (find_min(a) <= find_min_bot(a))
		{
			n = find_min(a);
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
			n = find_min_bot(a);
			
			while (n-- >= 0)
			{
				if (trier_b(b) == 1)
					oper("rrr", a, b);
				else
				oper("rra", a, b);
			}
			oper("pb", a, b);
			sort_b(a,b);
		}
}

void    push_max_a(t_stack *a, t_stack *b)
{
    int	n;

    if (find_max(a) <= find_max_bot(a))
		{
			n = find_max(a);
			while (n-- > 0)
				oper("ra", a, b);
			oper("pb", a, b);
		}
		else
		{
			n = find_max_bot(a);
			while (n-- >= 0)
				oper("rra", a, b);
			oper("pb", a, b);
		}
}

void    push_min_b(t_stack *a, t_stack *b)
{
    int	n;

    if (find_min(b) <= find_min_bot(b))
		{
			n = find_min(b);
			while (n-- > 0)
				oper("rb", a, b);
			oper("pa", a, b);
		}
		else
		{
			n = find_min_bot(b);
			while (n-- >= 0)
				oper("rrb", a, b);
			oper("pa", a, b);
		}
}

void    push_max_b(t_stack *a, t_stack *b)
{
    int	n;

    if (find_max(b) <= find_max_bot(b))
		{
			n = find_max(b);
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
			n = find_max_bot(b);
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
}

void    push_max_b_simple(t_stack *a, t_stack *b)
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