/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_big_choix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:23:27 by mpons             #+#    #+#             */
/*   Updated: 2022/01/28 13:23:30 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	ft_brk(t_stack *a, t_stack *b)
{
	if (b->size == 1)
	{
		oper("pa", a, b);
		return (1);
	}
	return (0);
}

void	petit_choix(t_stack *a, t_stack *b)
{
	int	t;
	int	tn;
	int	bt;

	t = a->top->value ; 
	tn = a->top->next->value;  
	bt = a->bot->value;
	{
		if (t <= tn && t <= bt)
		{
			oper("pb", a, b);
			return ;
		}
		if (tn <= t && tn <= bt)
		{
			oper("sa", a, b);
			if (is_sorted(a->top))
				return ;
			oper("pb", a, b);
			return ;
		}
		if (bt <= t && bt <= tn)
		{
			oper("rra", a, b);
			if (is_sorted(a->top))
				return ;
			oper("pb", a, b);
			return ;
		}
	}
}

void	big_choix(t_stack *a, t_stack *b)
{
//	print_stack(b, 'b');
	if (ft_brk(a, b))
		return;
	if (b->top->value >= b->top->next->value && b->top->value >= b->bot->value)
		oper("pa", a, b);
	if (ft_brk(a, b))
		return;
	if (b->top->next->value >= b->top->value && b->top->next->value >= b->bot->value)
	{
		oper("sb", a, b);
		oper("pa", a, b);
	}
	if (ft_brk(a, b))
		return;
	if (b->bot->value >= b->top->value && b->bot->value >= b->top->next->value)
	{
		oper("rb", a, b);
		oper("pa", a, b);
	}
	if (ft_brk(a, b))
		return;
}

//choix plus pres
void	choix_pp(t_stack *a, t_stack *b)
{
    while (1)
	{
		while (a->size > 2)
		{
			petit_choix(a, b);
		}
		oper("pb", a, b);
		while (b->size > 0)
			big_choix(a, b);
		if (is_sorted(a->top))
			return ;
	}
}
