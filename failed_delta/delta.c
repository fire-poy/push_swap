/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:25:01 by mpons             #+#    #+#             */
/*   Updated: 2022/01/28 13:25:03 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	find_min_delta(t_stack *a)
{
	int	t;
	int	tn;
	int	bt;
	int	v[6];
	int	d_min;
	int	min;
	int	max;
	int	i;

	find_min(a);
	min = a->min;
	find_max(a);
	max = a->max;
	
	t = a->top->value ; 
	tn = a->top->next->value;  
	bt = a->bot->value;

	v[0] = t - min;
	v[1] = tn - min;
	v[2] = bt - min;
	v[3] = max - t;
	v[4] = max - tn;
	v[5] = max - bt;
	i = -1;
	d_min = v[0];
//    {  printf("a->max =%d\n",a->max);
    // printf("a->min =%d\n",a->min);
    // printf("dm =%d\n",d_min);
    // printf("t =%d\n", t);
    // printf("tn =%d\n",tn);
    // printf("bt =%d\n",bt);}
//    }
    while (++i < 6)
	{
		if (d_min > v[i]) //si d_min es mas grande lo remplazamos
		   d_min = v[i];	
        //    printf("dm =%d\n",d_min);
    }
    // {// if (d_min == v[5])
    // {
    //     i = -1;
    //     while (++i < 5)
    //     {
    //         if (d_min < v[i])
    //             d_min = v[i];	
    //     }	
    // }
	// }
	return (d_min);
}	

//if (dt <= dtn && dt <= dbt && dt <= Dt && dt <= Dtn && dt <= )
void	a_delta_choix(t_stack *a, t_stack *b)
{
	int	dm;
	int	t;
	int	tn;
	int	bt;
	// int	piv;

	t = a->top->value ; 
	tn = a->top->next->value;  
	bt = a->bot->value;
	dm = find_min_delta(a);
	// piv = a->max - a->min / 2;
    // printf("dm =%d",dm);
  	if (dm == t - a->min)
	{
		oper("pb", a, b);
		return ;
	}
	if (dm == tn - a->min)
	{
		if (trier(b) == 2)
			oper("ss", a, b);
		else
			oper("sa", a, b);
		oper("pb", a, b);
		return ;
	}
	if (dm == bt - a->min)
	{
		oper("rra", a, b);
		oper("pb", a, b);
		return ;
	}
	if (dm == a->max - t)
	{if (trier(b) == 1)
			oper("rr", a, b);
		else
			oper("ra", a, b);
		return ;
	}
	if (dm == a->max - tn)
	{
		if (trier(b) == 2)
			oper("ss", a, b);
		else
			oper("sa", a, b);
		if (trier(b) == 1)
			oper("rr", a, b);
		else
			oper("ra", a, b);
		return ;
	}
    else
        petit_choix(a, b);
}

int	find_min_deltb(t_stack *b)
{
	int	t;
	int	tn;
	int	bt;
	int	v[6];
	int	d_min;
	int	min;
	int	max;
	int	i;

	find_min(b);
	min = b->min;
	find_max(b);
	max = b->max;
	t = b->top->value ; 
	tn = b->top->next->value;  
	bt = b->bot->value;
	v[0] = max -t;
	v[1] = max - tn;
	v[2] = max -bt;
	v[3] = t - min;
    v[4] = tn - min;
	v[5] = bt - min;
    i = -1;
	d_min = v[0];
    while (++i < 6)
	{
		if (d_min > v[i])
		   d_min = v[i];	
    }
    // if (d_min == v[5])
    // {
    //     i = -1;
    //     while (++i < 5)
    //     {
    //         if (d_min < v[i])
    //             d_min = v[i];	
    //     }	
    // }
	return (d_min);
}

//if (dt <= dtn && dt <= dbt && dt <= Dt && dt <= Dtn && dt <= )
void	b_delta_choix(t_stack *a, t_stack *b)
{
	int	dm;
	int	t;
	int	tn;
	int	bt;
	int	piv;

	t = b->top->value ; 
	tn = b->top->next->value;  
	bt = b->bot->value;
	dm = find_min_deltb(b);
	piv = b->max - b->min / 2;
	if (dm == t - b->min)
	{
		oper("rb", a, b);
		return ;
	}
	if (dm == tn - b->min)
	{
		if (trier_a(a) == 2)
        	oper("ss", a, b);
		else
			oper("sb", a, b);
		oper("rb", a, b);
		return ;
	}
	if (dm == b->max - t)
	{
		oper("pa", a, b);
		return ;
	}
	if (dm == b->max - tn)
	{
		if (trier_a(a) == 2)
        	oper("ss", a, b);
		else
        	oper("sb", a, b);
		oper("pa", a, b);
		return ;
	}
    if (dm == b->max - bt)
	{
		if (trier_a(a) == 1)
			oper("rrr", a, b);
		else
			oper("rrb", a, b);
		oper("pa", a, b);
		return ;
	}
	else
        big_choix(a, b);
}

void	choix_dpp(t_stack *a, t_stack *b)
{
    while (1)
	{
		while (a->size > 3)
		{
			a_delta_choix(a, b);
			if (b->size > 1)
				rev_sort_b(a, b);
		// print_stack(a, 'a');
		// print_stack(b, 'b');

		}	
        while (a->size > 1)
	    { 
			petit_choix(a, b);
			rev_sort_b(a, b);
		}
        oper("pb", a, b);
		// print_stack(a, 'a');
		// print_stack(b, 'b');
		while (b->size > 3)
        {
			b_delta_choix(a, b);
			if (a->size > 1)
				sort_a(a, b);
        }
        big_choix(a, b);
        big_choix(a, b);
        oper("pa", a, b);
        if (is_sorted(a->top))
			return ;
		// print_stack(a, 'a');
		// print_stack(b, 'b');
	}
}

