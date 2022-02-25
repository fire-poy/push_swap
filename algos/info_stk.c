/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:37:07 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:49:30 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	take_info_stk(t_stack *stk)
{
	stk->st_size = stk->size;
	find_min(stk);
	find_max(stk);
	stk->st_min = stk->min;
	stk->st_max = stk->max;
}

void	find_piv(t_stack *stk)
{
	if (stk->st_size > 50 && stk->size <= 120)
	{
		stk->min = find_min_val(stk);
		stk->piv = stk->min + (stk->size / 3);
	}
	if (stk->piv > 380)
	{
		stk->min = find_min_val(stk);
		stk->piv = stk->min + (stk->size / 3);
		return ;
	}
	if (stk->st_size > 120)
	{
		stk->piv += (stk->st_max / 11);
	}
}

void	find_values(t_stack *a, t_stack *b, t_ch *c)
{
	c->x1 = find_sous_piv(a);
	c->x2 = find_sous_piv_bot(a) + 1;
	c->y1 = find_next(a->h_val, b);
	c->y1_b = b->size - c->y1;
	c->y2 = find_next(a->h_val_b, b);
	c->y2_b = b->size - c->y2;
	c->a = bigger(c->x1, c->y1);
	c->b = c->x1 + c->y1_b;
	c->c = c->x2 + c->y2;
	c->d = bigger(c->x2, c->y2_b);
}
