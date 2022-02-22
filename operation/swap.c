/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:55 by mpons             #+#    #+#             */
/*   Updated: 2022/01/26 11:37:47 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

t_node	*ft_swap_links(t_node *top, t_node *new_top)
{
	new_top = top->next;
	top->prev = new_top;
	top->next = new_top->next;
	new_top->next->prev = top;
	new_top->prev = NULL;
	new_top->next = top;
	top = new_top;
	return (top);
}

void	ft_swap(t_stack *stk, char flag)
{
	if (stk->size < 2)
		return ;
    if (stk->size == 2)
		ft_rot(stk, 0);
    if (stk->size > 2)
		stk->top = ft_swap_links(stk->top, stk->top->next);
	if (flag == 'a')
		ft_putendl_fd("sa", 1);
	if (flag == 'b')
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (a->size > 1 || b->size > 1)
		ft_putendl_fd("ss", 1);
}
