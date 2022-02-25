/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:16:45 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:20:11 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_one(t_stack *a, t_stack *b)
{
	if (b->size == 0)
	{
		b->top = a->top;
		b->bot = b->top;
	}
	if (b->size > 0)
	{
		b->top->prev = a->top;
		a->top->next = b->top;
		b->top = a->top;
	}
	a->top = NULL;
	a->bot = NULL;
}

void	ft_push_pop(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		ft_push_one(a, b);
	if (a->size > 1)
	{	
		if (b->size == 0)
		{
			b->top = a->top;
			b->bot = b->top;
			a->top = a->top->next;
			a->top->prev = NULL;
			b->top->next = NULL;
		}
		else
		{
			b->top->prev = a->top;
			a->top = a->top->next;
			a->top->prev = NULL;
			b->top->prev->next = b->top;
			b->top = b->top->prev;
		}
	}
	a->size--;
	b->size++;
}

void	ft_push(t_stack *a, t_stack *b, char flag)
{
	if (a->size == 0)
		return ;
	ft_push_pop(a, b);
	if (flag == 'a')
		ft_putendl_fd("pa", 1);
	if (flag == 'b')
		ft_putendl_fd("pb", 1);
}
