/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:58 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 15:35:41 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int trier_a(t_stack *s)
{
    int	t;
	int	tn;
	int	bt;

    if (s->size < 2)
        return (0);
	t = s->top->value ; 
	tn = s->top->next->value;  
	bt = s->bot->value;
	if (t > bt)
        return (2); //ra el mas pequeno arriba
    return (0);
}

int trier_b(t_stack *s)
{
    int	t;
	int	tn;
	int	bt;

    if (s->size < 2)
        return (0);
	t = s->top->value ; 
	tn = s->top->next->value;  
	bt = s->bot->value;
	if (t < bt)
	    return (2); //rb el mas pequeño abajo
    return (0);
}

void sort_a(t_stack *a, t_stack *b)
{
	if (trier_a(a) == 1)
		oper("rra", a, b);
	if (trier_a(a) == 2)
		oper("ra", a, b);		
    if (trier_a(a) == 3)
		oper("sa", a, b);
}

void sort_b(t_stack *a, t_stack *b)
{
	// print_stack(b, 'b'); 
	if (trier_b(b) == 1)
		oper("rrb", a, b);
	if (trier_b(b) == 2)
		oper("rb", a, b);		
    if (trier_b(b) == 3)
		oper("sb", a, b);
}