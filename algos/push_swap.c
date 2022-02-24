/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:37:21 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 20:31:51 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//push_min b, push a
void	push_swap_simple(t_stack *a, t_stack *b) 
{
	while (a->size > 0)
		push_min_a_simple(a, b);
	while (b->size > 0)
		oper("pa", a, b);
}

void	push_swap_piv(t_stack *a, t_stack *b, t_ch *c)
{
	while (1)
	{
		find_piv(a);
		while (a->size > 0)
		{
			if (push_sous_piv(a, b, c) == -1)// il nya pas de nro dessous le piv
			{
				find_piv(a);
			}
			// print_stack(a, 'a');	
			// print_stack(b, 'b');	
		}
		while (b->size > 0)
		{
			push_max_b_simple(a,b);
			// if (push_sur_piv(a, b) == -1)
				// find_piv2(a,b);
		}
			// print_stack(a, 'a');	
		if (is_sorted(a->top) == 1)
			break;
	}
}
/*



// while (b->size > 0)
			// push_max_b_simple(a ,b);
		
		*/