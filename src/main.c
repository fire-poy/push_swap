/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:13:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 19:52:19 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_ch	*init_st(void)
{
	t_ch *st;

	st = malloc(sizeof(t_ch));
	/*
	st->x1;
	st->c->x2;
	st->y1;
	st->y1_b;
	st->y2;
	st->y2_b;
    st->A; 
	st->B; 
	st->C; 
	st->D;
	*/
	return (st);
}

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
		// print_piv(a);
		free_stack(a);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_ch *c;

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
		c = init_st();
		replace(a);
		if (a->size == 5)
			sort_5(a, b);
		if (a->size == 3)
			sort_3(a, b);
		if (a->size == 2)
			oper("sa", a, b);
		sorted(a);
		take_info_stk(a);
		push_swap_piv(a, b, c);
		// print_stack(a, 'a');
		sorted(a);
	}
	return (0);
}
		// if (is_sorted(a->top) == 1)
		// 	printf("Weee");
		// print_stack(b, 'b');