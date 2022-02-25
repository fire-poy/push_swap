/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:27:49 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:20:45 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_revrot(t_stack *stk, char flag)
{
	if (stk->size < 2)
		return ;
	stk->bot->next = stk->top;
	stk->top->prev = stk->bot;
	stk->top = stk->bot;
	stk->bot = stk->bot->prev;
	stk->top->prev = NULL;
	stk->bot->next = NULL;
	if (flag == 'a')
		ft_putendl_fd("rra", 1);
	if (flag == 'b')
		ft_putendl_fd("rrb", 1);
}

void	ft_revrot_2(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_revrot(a, 0);
	ft_revrot(b, 0);
	ft_putendl_fd("rrr", 1);
}

void	ft_rot(t_stack *stk, char flag)
{
	if (stk->size < 2)
		return ;
	stk->top->prev = stk->bot;
	stk->bot->next = stk->top;
	stk->bot = stk->top;
	stk->top = stk->top->next;
	stk->bot->next = NULL;
	stk->top->prev = NULL;
	if (flag == 'a')
		ft_putendl_fd("ra", 1);
	else if (flag == 'b')
		ft_putendl_fd("rb", 1);
}

void	ft_rot_2(t_stack *a, t_stack *b)
{
	ft_rot(a, 0);
	ft_rot(b, 0);
	if (a->size > 1 || b->size > 1)
		ft_putendl_fd("rr", 1);
}
