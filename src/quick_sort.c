/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:22:37 by mpons             #+#    #+#             */
/*   Updated: 2022/01/26 12:33:04 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	find_min(t_stack *a)
{
	t_node	*top;
	int		min;
	int		pos;
	int		i;

	top = a->top;
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
	a->pos = pos;
	a->min = min;
	return (pos);
}
		
int	find_min_bot(t_stack *a)
{
	t_node	*bot;
	int		min;
	int		pos;
	int		i;

	bot = a->bot;
	min = bot->value;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value < min)
		{
			min = bot->value;
			pos = i;
		}
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	a->pos = pos;
	a->min = min;
	return (pos);
}

int	find_max(t_stack *a)
{
	t_node	*top;
	int		max;
	int		pos;
	int		i;

	top = a->top;
	max = top->value;
	i = -1;
	while (top)
	{
		i++;
		if (top->value > max)
		{
			max = top->value;
			pos = i;
		}
		if (!top->next)
			break ;
		top = top->next;
	}
	a->pos = pos;
	a->max = max;
	return (max);
}
		
int	find_max_bot(t_stack *a)
{
	t_node	*bot;
	int		max;
	int		pos;
	int		i;

	bot = a->bot;
	max = bot->value;
	i = -1;
	while (bot)
	{
		i++;
		if (bot->value > max)
		{
			max = bot->value;
			pos = i;
		}
		if (!bot->prev)
			break ;
		bot = bot->prev;
	}
	a->pos = pos;
	a->max = max;
	return (max);
}
/*
void	pivots(t_stack *a)
{
	int min;
	int max;

	min = find_min(a);
	max = find_max(a);
	big_p = (min + max) / 2;
	small_p = big_p / 2;
}
*/
int	find_next(t_stack *a)
{
	t_node	*top;
	int		max;
	int		pos;
	int		i;

	top = a->top;
	max = top->value;
	i = -1;
	while (top)
	{
		i++;
		if (top->value > max)
		{
			max = top->value;
			pos = i;
		}
		if (!top->next)
			break ;
		top = top->next;
	}
	return (max);
}
