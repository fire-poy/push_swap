/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:37:21 by mpons             #+#    #+#             */
/*   Updated: 2022/01/26 14:13:23 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	n;

	while (a->size > 0)
	{
		if (find_min(a) <= find_min_bot(a))
		{
			n = find_min(a);
			while (n > 0)
			{
//				printf("n = %d\n", n);
				oper("rra", a, b);
				n--;
			}
			oper("pa", a, b);
			/*
			*/
		}
		else
		{
			n = find_min_bot(a);
			while (n-- >= 0)
				oper("ra", a, b);
			oper("pa", a, b);
		}
//		print_stack(a, 'a');
	}
	while (b->size > 0)
		oper("pb", a, b);
}
/*	     
		printf("n = %d\n", n);
*/
void	sort_larger(t_stack *a, t_stack *b)
{
	int		i;
	int		max;
	int		size;

	i = 1;
	max = 0;
	size = a->size;
	while (a)
	{
		if (size <= 100)
			max += a->size / 5 - 2
		else
			max += size / 11 - 2
		while (i <= max)
		{
			if (!(a))
				break ;
			if (a->norm <= max)
			{
				oper("pb", a, b);
				i++;
			}
			else
				oper("ra", a, b);
		}
	}
	i--;
		push_b(stacka, stackb, i, max);
	}
}
