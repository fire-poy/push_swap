/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pivot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:34:52 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 15:05:31 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void find_piv(t_stack *stk)
{
    find_min(stk);
    find_max(stk);
    stk->piv = (stk->max + stk->min) / 2;
}

int	find_min_piv(t_stack *a)
{
	t_node	*top;
	int		i;

	top = a->top;
	i = -1;
	while (top)
	{
		i++;
		if (top->value <= a->piv)
        	return (i);
		if (!top->next)
			break ;
		top = top->next;
	}
	return (-1);
}
		
//find pos < min depuis le bottom		
int	find_min_piv_bot(t_stack *a)
{
	t_node	*bot;
	int		i;

	bot = a->bot;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value <= a->piv)
            return (i);
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	return (-1);
}

int	find_max_piv(t_stack *a)
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
int	find_max_piv_bot(t_stack *a)
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



