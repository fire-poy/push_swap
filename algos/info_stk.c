/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:28:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 20:39:24 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void take_info_stk(t_stack *stk)
{
	stk->st_size = stk->size;
	find_min(stk);
	find_max(stk);
	stk->st_min = stk->min;
	stk->st_max = stk->max;
	stk->i = 0;
}

int	find_min_val(t_stack *stk)
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
	return (min);
}

int	find_max_val(t_stack *stk)
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
	return (max);
}

void find_piv(t_stack *stk)
{
	stk->min = find_min_val(stk);
	stk->piv = stk->min + (stk->size / 3);
	// if (stk->st_size <= 50)
    // 	stk->piv += (stk->st_max / 3);
	// if (stk->st_size > 50 && stk->size <= 120)
    // 	stk->piv += (stk->st_max / 5);
	// if (stk->st_size > 120)
    // 	stk->piv += (stk->st_max / 11);
	// stk->mem[stk->i] = stk->piv;
	// stk->i++;
	// printf("%s piv = %d \n", YELLOW, stk->piv);
}
	// if (stk->piv < find_min_val(stk))
	// 	stk->piv = find_max_val(stk);

void find_piv2(t_stack *stk,t_stack *b)
{
	if (stk->st_size <= 50)
    	stk->piv -= (stk->st_max + stk->st_min) / 3;
	if (stk->st_size > 50 && stk->size <= 120)
    	stk->piv -= (stk->st_max + stk->st_min) / 5;
	if (stk->st_size > 120)
    	stk->piv -= (stk->st_max + stk->st_min) / 11;
	if (stk->piv > find_max_val(b))
		stk->piv = find_max_val(b);
	b->piv = stk->piv;
}

void	print_piv(t_stack *a)
{
	int i = 0;

	printf("a->i = %d\n", a->i);
	while (i++ < a->i)
		printf("piv = %d\n", a->mem[i]);
}