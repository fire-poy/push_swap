/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:33:58 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 15:25:55 by mpons            ###   ########.fr       */
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
	if (bt < t && t < tn)
        return (1); //rra el mas pequeno arriba
    if (t > bt) 
        return (2); //ra el mas grande abajo
    if (t > tn)
        return (3); //sa el mas grande abajo
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
    if (bt > t && t > tn)
        return (1); //rrb el mas grande arriba
	if (t < bt)
	    return (2); //rb el mas pequeño abajo
    if (t < tn)
        return (3); //sb el mas pequeño abajo
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
