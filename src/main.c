/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:13:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 16:10:21 by mpons            ###   ########.fr       */
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

void	sorted(t_stack *a)
{
	if (is_sorted(a->top))
	{
		free_stack(a);
		exit(0);
	}
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
		if (a->size == 5)
			sort_5(a, b);
		sorted(a);
		if (a->size == 3)
			sort_3(a, b);
		if (a->size == 2)
			oper("sa", a, b);
		sorted(a);
		// push_swap(a, b);
		push_swap_piv(a, b);
		// if (is_sorted(a->top) == 1)
		// 	printf("Weee");
		sorted(a);
		// print_stack(a, 'a');
		// print_stack(b, 'b');
	}
	return (0);
}
/*
		choix_pp(a, b);
		print_stack(a,'a');

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
