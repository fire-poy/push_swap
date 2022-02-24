/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:25:01 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 17:26:59 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//return pos de le plus pres
int	find_next(int ref, t_stack *stk)
{
	t_node	*top;
	int		delta;
	int		pos;
	int		i;

    if (stk->size == 0)
        return (0);
	top = stk->top;
    delta = ABS(top->value - ref);
    pos = 0;
	i = -1;
	while (top)
	{
		i++;
		if ((ABS(top->value - ref)) < delta)
		{
			delta = ABS(top->value - ref);
			pos = i;
		}
		if (!top->next)
			break ;
		top = top->next;
	}
    return (pos);
}
        // if (ref == 1)
        //     printf("%s delta = %d \n top-value = %d \n ref = %d", MAGENTA, delta, top->value , ref);

//rotate b and push a to b
void    push_next(t_stack *a, t_stack *b)
{
    int	n;

    n = find_next(a->top->value, b);
    if (n < b->size - n)
    {
		while (n-- > 0)
				oper("rb", a, b);
			oper("pb", a, b);
    }
    else 
    {    
        n = b->size - n; 
        while (n-- >= 0)
            oper("rrb", a, b);
        oper("pb", a, b);
    }
    if (b->size >= 2)
    {
        if (b->top->value < b->top->next->value)
            oper("sb", a, b);
    }
}