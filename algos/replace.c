/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:19:35 by mpons             #+#    #+#             */
/*   Updated: 2022/02/24 16:35:51 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    sort_tab(int *tab, int size)
{
    int i = 0;
	int	temp;
    
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

void find_pos_and_replace(t_stack *a, int *tab)
{
    int i;
    t_node *top;

    top = a->top;
    while (top)
    {
        i = -1; 
        while (++i < a->size)
        {
            if(top->value == tab[i])
            {
                top->value = i;
                break ;
            }
        }
        if (!top->next)
            break; 
        top = top->next;    
    }    
}

void    print_tab(int *tab, int size)
{
    int i;
    
    i = -1;
    while (++i < size)
    {
        printf("tab[i] = %d\n", tab[i]);
    }
}

void    replace(t_stack *a)
{
    int i;
    int *tab;
    t_node *top;

    top = a->top;
    tab = malloc(a->size * sizeof(int));
    i = 0;
    while (top)
    {
        tab[i++] = top->value;
        if (!top->next)
            break; 
        top = top->next;    
    }    
    sort_tab(tab, a->size);
    // print_tab(tab, a->size);
    find_pos_and_replace(a, tab);
	// print_stack(a, 'a');
    free(tab);
    tab = NULL;
}
