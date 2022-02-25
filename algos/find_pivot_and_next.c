/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot_and_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:34:52 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:38:59 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//return pos du plus pres
int	find_next(int ref, t_stack *stk)
{
	t_node	*top;
	int		delta;
	int		pos;
	int		i;

	if (stk->size == 0)
		return (0);
	top = stk->top;
	delta = v_absolute(top->value - ref);
	pos = 0;
	i = -1;
	while (top)
	{
		i++;
		if ((v_absolute(top->value - ref)) < delta)
		{
			delta = v_absolute(top->value - ref);
			pos = i;
		}
		if (!top->next)
			break ;
		top = top->next;
	}
	return (pos);
}

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
