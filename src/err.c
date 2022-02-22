/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:21:59 by mpons             #+#    #+#             */
/*   Updated: 2022/01/26 11:31:15 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	err_m(char *e)
{
	ft_putendl_fd(e, 2);
	exit (1);
}

void	free_stack(t_stack *a)
{
	t_node *tmp;
	t_node *tmp_2;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->next)
		{
			tmp_2 = tmp->next;
			free (tmp);
			tmp = tmp_2;
		}
		else
		{
			tmp_2 = NULL;
			break;
		}
	}
	free (a);
	a = NULL;
}

void	print_top(t_stack *stk)
{
		printf("stk->top->prev = %p\n", stk->top->prev);
		printf("stk->top = %p\n", stk->top);
		printf("stk->top->next = %p\n", stk->top->next);
		if (stk->top->next != stk->bot)	
			printf("!!stk->top->next->prev = %p\n", stk->top->next->prev);
}

void	print_bot(t_stack *stk)
{
		printf("stk->bot->prev = %p\n", stk->bot->prev);
		printf("stk->bot = %p\n", stk->bot);
		printf("stk->bot->next = %p\n", stk->bot->next);
}

void	print_top_bot(t_stack *stk, char flag)
{
		printf("stack %c_size =%d\n", flag, stk->size);
		print_top(stk);
		printf("\n");
		print_bot(stk);
}

void	print_stack(t_stack *stk, char flag)
{
	t_node *top;
	
	if (flag == 'a')
		printf("%s stack %c_size =%d\n", GREEN, flag, stk->size);
	if (flag == 'b')
		printf("%s stack %c_size =%d\n", RED, flag, stk->size);
	if (stk->top)
	{
		top = stk->top;
		while (top->next)
		{
			printf("node = %d\n", top->value);
			top = top->next;
		}
			printf("node = %d\n", top->value);
	}
}
