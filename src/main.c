/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:13:01 by mpons             #+#    #+#             */
/*   Updated: 2022/01/26 12:07:36 by mpons            ###   ########.fr       */
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
				err_m("error: numbers are duplicated");
			if (tmp->next)
				tmp = tmp->next;
			else 
				break ;
		}
		a = a->next;
	}
}

int		is_sorted(t_node *tmp)
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

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac > 1)
	{
		a = init_stack();
		check_arg(av, a);
		check_double(a->top);
		if (is_sorted(a->top))
		{
			free_stack(a);
			return (0);
		}
		b = init_stack();
		push_swap(a,b);
		if (is_sorted(a->top))
		{
			free_stack(a);
			return (0);
		}
	}
	return (0);
}
/*
		print_stack(a,'a');
		print_top_bot(a,'a');
		oper("sa",a,b);
		print_stack(b,'b');

		while (a->size > 0)
		{
			print_stack(a,'a');
			printf ("min %d\n",find_min(a));
			oper("pa",a,b);
		}
*/
