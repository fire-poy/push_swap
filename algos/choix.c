/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:53:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:50:15 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	choix(t_stack *a, t_stack *b, t_ch *c)
{
	find_values(a, b, c);
	if (c->a <= c->b && c->a <= c->c && c->a <= c->d)
	{
		choix1(a, b, c);
		return (1);
	}
	if (c->b <= c->a && c->b <= c->c && c->b <= c->d)
	{
		choix2(a, b, c);
		return (2);
	}
	if (c->c <= c->a && c->c <= c->b && c->c <= c->d)
	{
		choix3(a, b, c);
		return (3);
	}
	if (c->d <= c->a && c->d <= c->b && c->d <= c->c)
	{
		choix4(a, b, c);
		return (4);
	}
	return (0);
}
