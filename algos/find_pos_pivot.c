/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:34:52 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 19:20:17 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_sous_piv(t_stack *a)
{
	t_node	*top;
	int		i;

	top = a->top;
	i = -1;
	while (top)
	{
		i++;
		if (top->value <= a->piv)
		{
			a->h_val = top->value;
        	return (i);
		}
		if (!top->next)
			break ;
		top = top->next;
	}
	return (-1);
}
		
//find pos < min depuis le bottom		
int	find_sous_piv_bot(t_stack *a)
{
	t_node	*bot;
	int		i;

	bot = a->bot;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value <= a->piv)
		{
			a->h_val_b = bot->value;
        	return (i);
		}
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	return (-1);
}

int	find_sur_piv(t_stack *a)
{
	t_node	*top;
	int		i;

	top = a->top;
	i = -1;
	while (top)
	{
		i++;
		if (top->value >= a->piv)
        	return (i);
		if (!top->next)
			break ;
		top = top->next;
	}
	return (-1);
}
		
//find pos > piv depuis le bottom		
int	find_sur_piv_bot(t_stack *a)
{
	t_node	*bot;
	int		i;

	bot = a->bot;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value >= a->piv)
            return (i);
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	return (-1);
}



/*
void	choix(t_stack *a, t_stack *b)
{
	ch->x1 = find_sous_piv(a);
	ch->x2 = find_sous_piv_bot(a) + 1;
	ch->y1 = find_next(a->h_val, b);
	ch->y1_b = b->size - y1;
	ch->y2 = find_next(a->h_val_b, b);
	ch->y2_b = b->size - y2;

	ch->A = BIG(x1,y1);
	ch->B = x1 + y1_b;
	ch->C = x2 + y2;
	ch->D = BIG(x2,y2_b);
	// printf("x1 =%d\n", x1);
	// printf("x2 =%d\n", x2);
	// printf("y1 =%d\n", y1);
	// printf("y1_b =%d\n", y1_b);
	// printf("y2 =%d\n", y2);
	// printf("y2_b =%d\n\n", y2_b);
	// if ((x1 + y1_b < x2 + y2) && (x1 + y1_b < BIG(x1,y1)) && (x1 + y1_b < BIG(x2,y2_b)))
	if (ch->B < ch->A && ch->B < ch->C && ch->B < ch->D)
		// printf("x1 + y1_b = %d \n", (x1 + y1_b));
		return (2);
	// if ((x2 + y2 < x1 + y1_b) && (x2 + y2 < BIG(x1,y1)) && ((x2+y2) < BIG(x2,y2_b)))
	if (ch->C < ch->A && ch->C < ch->B && ch->C < ch->D)
		// printf ("x2 + y2 = %d\n", (x2 + y2));
		return(3);
	// if ((BIG(x1,y1) < x1 + y1_b) && (BIG(x1,y1) < x2 + y2) && (BIG(x1,y1) < BIG(x2,y2_b)))
	if (ch->A < ch->B && ch->A < ch->C && ch->A < ch->D)
		// printf ("BIG(x1,y1) = %d \n", BIG(x1,y1));
		return(1);
	// if ((BIG(x2,y2_b) < x1 + y1_b) && (BIG(x2,y2_b) < x2 + y2) && (BIG(x2,y2_b) < BIG(x1,y1)))
	if (D < A && D < ch->B && ch->D < ch->C)
		// printf ("BIG(x2,y2_b) = %d \n", BIG(x2,y2_b));
		return(4);
}
*/