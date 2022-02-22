/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:22:37 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 17:04:21 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//find pos min
int	find_min(t_stack *stk)
{
	t_node	*top;
	int		min;
	int		pos;
	int		i;

	top = stk->top;
	min = top->value;
	i = -1;
	while (top)
	{
		i++;
		if (top->value <= min)
		{
			min = top->value;
			pos = i;
		}
		if (!top->next)
			break ;
		top = top->next;
	}
	stk->pos = pos;
	stk->min = min;
	return (pos);
}
		
//find pos min depuis le bottom		
int	find_min_bot(t_stack *stk)
{
	t_node	*bot;
	int		min;
	int		pos;
	int		i;

	bot = stk->bot;
	min = bot->value;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value <= min)
		{
			min = bot->value;
			pos = i;
		}
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	stk->pos = pos;
	stk->min = min;
	return (pos);
}

//find pos max
int	find_max(t_stack *stk)
{
	t_node	*top;
	int		max;
	int		pos;
	int		i;

	top = stk->top;
	max = top->value;
	i = -1;
	while (top)
	{
		i++;
		if (top->value >= max)
		{
			max = top->value;
			pos = i;
		}
		if (!top->next)
			break ;
		top = top->next;
	}
	stk->pos = pos;
	stk->max = max;
	return (pos);
}
		
//find pos max depuis le bottom
int	find_max_bot(t_stack *stk)
{
	t_node	*bot;
	int		max;
	int		pos;
	int		i;

	bot = stk->bot;
	max = bot->value;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value >= max)
		{
			max = bot->value;
			pos = i;
		}
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	stk->pos = pos;
	stk->max = max;
	return (pos);
}

