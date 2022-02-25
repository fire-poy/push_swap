/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:21:59 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:12:31 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	err_m(void)
{
	ft_putendl_fd("Error", 2);
	exit (1);
}

void	free_stack(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp_2;

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
			break ;
		}
	}
	free (a);
	a = NULL;
}

int	v_absolute(int x)
{
	if (x > 0)
		return (x);
	else
		return (-x);
}

int	bigger(int p, int q)
{
	if (p > q)
		return (p);
	else
		return (q);
}
