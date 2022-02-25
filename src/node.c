/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:01:58 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:11:27 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	stk->top = NULL;
	stk->bot = NULL;
	stk->size = 0;
	stk->min = 0;
	stk->max = 0;
	stk->pos = 0;
	stk->piv = 0;
	return (stk);
}

int	ft_check_and_atoi(const char *str)
{
	int		i;
	int		sign;
	long	value;

	value = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			err_m();
		value *= 10;
		value += str[i] - '0';
		if (value >= MAX_INT || value <= MIN_INT)
			err_m();
		i++;
	}
	return (value * sign);
}

t_node	*ft_create_node(char *str)
{
	t_node	*adr;

	adr = malloc(sizeof(t_node));
	if (!adr)
		return (NULL);
	adr->value = ft_check_and_atoi(str);
	adr->prev = NULL;
	adr->next = NULL;
	return (adr);
}

t_stack	*ft_add_stack(t_stack *a, char *val)
{
	t_node	*new_n;

	new_n = ft_create_node(val);
	if (new_n == NULL)
		return (NULL);
	a->size++;
	if (a->top == NULL)
	{
		a->top = new_n;
		return (a);
	}
	if (a->top->next == NULL)
	{
		a->bot = new_n;
		a->top->next = a->bot;
		a->bot->prev = a->top;
	}
	else
	{
		a->bot->next = new_n;
		new_n->prev = a->bot;
		a->bot = new_n;
	}
	return (a);
}

void	check_arg(char **av, t_stack *a)
{
	int		i;
	int		j;
	char	**arg;

	i = 0;
	while (av[++i])
	{
		if (ft_strchr(av[i], ' '))
		{
			arg = ft_split(av[i], ' ');
			j = -1;
			while (arg[++j])
			{
				a = ft_add_stack(a, arg[j]);
				if (a == NULL)
					err_m();
			}
			free (arg);
		}
		else
			a = ft_add_stack(a, av[i]);
	}
}
