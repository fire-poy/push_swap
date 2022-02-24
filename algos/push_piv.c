/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_piv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:53:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 20:31:39 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	choix(t_stack *a, t_stack *b, t_ch *c);

void	choix1(t_stack *a, t_stack *b, t_ch *c)
{
    int	dif;

	if (c->x1 <= c->y1)
	{
		dif = c->y1 - c->x1;
		while (c->x1-- > 0)
			oper("rr", a, b);
		while (dif-- > 0)
			oper("rb", a, b);
	}
	else
	{
		dif = c->x1 - c->y1;
		while (c->y1-- > 0)
			oper("rr", a, b);
		while (dif-- > 0)
			oper("ra", a, b);
	}
}

void	choix2(t_stack *a, t_stack *b, t_ch *c)
{
		while (c->x1-- > 0)
			oper("ra", a, b);
		while (c->y1_b-- > 0)
			oper("rrb", a, b);
}

void	choix3(t_stack *a, t_stack *b, t_ch *c)
{
		while (c->x2-- > 0)
			oper("rra", a, b);
		while (c->y2-- > 0)
			oper("rb", a, b);
}

void	choix4(t_stack *a, t_stack *b, t_ch *c)
{
    int	dif;

	if (c->x2 <= c->y2_b)
	{
		dif = c->y2_b - c->x2;
		while (c->x2-- > 0)
			oper("rrr", a, b);
		while (dif-- > 0)
			oper("rrb", a, b);
	}
	else
	{
		dif = c->x2 - c->y2_b;
		while (c->y2_b-- > 0)
			oper("rrr", a, b);
		while (dif-- > 0)
			oper("rra", a, b);
	}
}

// find_sous_piv aporte la valeur quelque part pour a la fois faire find_next et pouvoir faire rr

// find_sous_piv  A => (pos + val)
// find_next val en B => pos 

// n < find_next B

	// printf ("%s na = %d, nb = %d\n", BLUE, na , nb);

//je pourais comparer delta entre na nb depuis top et depuis en bas
int    push_sous_piv(t_stack *a, t_stack *b, t_ch *c)
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

int	choix(t_stack *a, t_stack *b, t_ch *c)
{
	c->x1 = find_sous_piv(a);
	c->x2 = find_sous_piv_bot(a) + 1;
	c->y1 = find_next(a->h_val, b);
	c->y1_b = b->size - c->y1;
	c->y2 = find_next(a->h_val_b, b);
	c->y2_b = b->size - c->y2;
//
	c->A = BIG(c->x1, c->y1);
	c->B = c->x1 + c->y1_b;
	c->C = c->x2 + c->y2;
	c->D = BIG(c->x2,c->y2_b);
	// printf("c->x1 =%d\n", c->x1);
	// printf("c->x2 =%d\n", c->x2);
	// printf("c->y1 =%d\n", c->y1);
	// printf("c->y1_b =%d\n", c->y1_b);
	// printf("c->y2 =%d\n", c->y2);
	// printf("c->y2_b =%d\n\n", c->y2_b);
	// if ((BIG(c->x1,c->y1) < c->x1 + c->y1_b) && (BIG(c->x1,c->y1) < c->x2 + c->y2) && (BIG(c->x1,c->y1) < BIG(c->x2,c->y2_b)))
	if (c->A <= c->B && c->A <= c->C && c->A <= c->D)
	{
		// printf ("BIG(c->x1,c->y1) = %d \n", BIG(c->x1,c->y1));
		choix1(a,b,c);
		return(1);
	}
	// if ((c->x1 + c->y1_b < c->x2 + c->y2) && (c->x1 + c->y1_b < BIG(c->x1,c->y1)) && (c->x1 + c->y1_b < BIG(c->x2,c->y2_b)))
	if (c->B <= c->A && c->B <= c->C && c->B <= c->D)
	{
		// printf("c->x1 + c->y1_b = %d \n", (c->x1 + c->y1_b));
		choix2(a,b,c);
		return (2);
	}
	// if ((c->x2 + c->y2 < c->x1 + c->y1_b) && (c->x2 + c->y2 < BIG(c->x1,c->y1)) && ((c->x2+c->y2) < BIG(c->x2,c->y2_b)))
	if (c->C <= c->A && c->C <= c->B && c->C <= c->D)
	{
		// printf ("c->x2 + c->y2 = %d\n", (c->x2 + c->y2));
		choix3(a,b,c);
		return(3);
	}
	// if ((BIG(c->x2,c->y2_b) < c->x1 + c->y1_b) && (BIG(c->x2,c->y2_b) < c->x2 + c->y2) && (BIG(c->x2,c->y2_b) < BIG(c->x1,c->y1)))
	if (c->D <= c->A && c->D <= c->B && c->D <= c->C)
	{
		// printf ("BIG(c->x2,c->y2_b) = %d \n", BIG(c->x2,c->y2_b));
		choix4(a,b,c);
		return(4);
	}
	return (0);
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
