/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:13:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:47:59 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_double(t_node *a)
{
	int		val;
	t_node	*tmp;

	while (a->next)
	{
		val = a->value;
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == val)
				err_m();
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		a = a->next;
	}
}

int	is_sorted(t_node *tmp)
{
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	sorted(t_stack *a)
{
	if (is_sorted(a->top))
	{
		free_stack(a);
		exit(0);
	}
}

void	small_size(t_stack *a, t_stack *b)
{	
	if (a->size == 5)
		sort_5(a, b);
	if (a->size == 3)
		sort_3(a, b);
	if (a->size == 2)
		oper("sa", a, b);
	sorted(a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_ch	c;

	if (ac > 1)
	{
		a = init_stack();
		check_arg(av, a);
		check_double(a->top);
		sorted(a);
		b = init_stack();
		replace(a);
		small_size(a, b);
		take_info_stk(a);
		push_swap_piv(a, b, &c);
		sorted(a);
	}
	return (0);
}
