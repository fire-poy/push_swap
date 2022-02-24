/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_piv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:53:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 17:27:27 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// find_sous_piv aporte la valeur quelque part pour a la fois faire find_next et pouvoir faire rr

// find_sous_piv  A => (pos + val)
// find_next val en B => pos 

// n < find_next B


//je pourais comparer delta entre na nb depuis top et depuis en bas
int    push_sous_piv(t_stack *a, t_stack *b)
{
    int	na;
    int	nb;
    int	dif;

    if (find_sous_piv(a) == -1)
        return (-1);
    else 
	{
		na = find_sous_piv(a);
		nb = find_next(a->h_val, b);
		// printf ("%s na = %d, nb = %d\n", BLUE, na , nb);
		if (na <= nb)
		{
			dif = nb - na;
			while (na-- > 0)
				oper("rr", a, b);
			while (dif-- > 0)
				oper("rb", a, b);
		}
		else
		{
			dif = na - nb;
			while (nb-- > 0)
				oper("rr", a, b);
			while (dif-- > 0)
				oper("ra", a, b);
		}
		oper("pb", a, b);
		if (b->size >= 2)
	    {
			if (b->top->value < b->top->next->value)
       			oper("sb", a, b);
		}
	}
    return (1);
}

	// else
	// 	{
	// 		n = find_sous_piv_bot(a);
	// 		while (n-- > 0)
	// 		{
	// 			oper("rra", a, b);
	// 		}
	// 		oper("pb", a, b);
	// 	}
int   push_sur_piv(t_stack *a, t_stack *b)
{
    int	n;

    if (find_sur_piv(b) == -1)
        return (-1);
    if (find_sur_piv(b) <= find_sur_piv_bot(b))
		{
			n = find_sur_piv(b);
			while (n-- > 0)
			{
				if (trier_a(a) == 2)
					oper("rr", a, b);
				else
					oper("rb", a, b);
			}
			oper("pa", a, b);
		}
		else
		{
			n = find_sur_piv_bot(b);
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
