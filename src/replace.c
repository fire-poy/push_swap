/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:19:35 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:48:48 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = temp;
			i = -1;
		}
		i++;
	}
}

void	find_pos_and_replace(t_stack *a, int *tab)
{
	int		i;
	t_node	*top;

	top = a->top;
	while (top)
	{
		i = -1;
		while (++i < a->size)
		{
			if (top->value == tab[i])
			{
				top->value = i;
				break ;
			}
		}
		if (!top->next)
			break ;
		top = top->next;
	}
}

void	replace(t_stack *a)
{
	int		i;
	int		*tab;
	t_node	*top;

	top = a->top;
	tab = malloc(a->size * sizeof(int));
	i = 0;
	while (top)
	{
		tab[i++] = top->value;
		if (!top->next)
			break ;
		top = top->next;
	}
	sort_tab(tab, a->size);
	find_pos_and_replace(a, tab);
	free(tab);
	tab = NULL;
}
