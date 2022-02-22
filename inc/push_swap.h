/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:42 by mpons             #+#    #+#             */
/*   Updated: 2022/02/22 17:04:09 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

//terminal color
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define DEFAULT "\033[0m"

// #define MAX(x, m) x - m
// #define MIN(x, m) m - x

typedef struct s_node t_node;

struct s_node
{
    int     value;
    t_node  *prev;
    t_node  *next;
};	

typedef struct s_stack
{
    int     size;
	int		min;
	int		max;
	int		pos;
    int     piv;
    t_node  *top;
    t_node  *bot; 
}   t_stack;

void	err_m(char *e);
void	push_swap(t_stack *a, t_stack *b);
void	free_stack(t_stack *a);

//ALGO
int		find_min(t_stack *stk);
int		find_min_bot(t_stack *stk);
int		find_max(t_stack *stk);
int		find_max_bot(t_stack *stk);
void    push_min_a(t_stack *a, t_stack *b);
void    push_max_a(t_stack *a, t_stack *b);
void    push_min_b(t_stack *a, t_stack *b);
void    push_max_b(t_stack *a, t_stack *b);

//3 et 5
void    sort_3(t_stack *a, t_stack *b);
void    sort_5(t_stack *a, t_stack *b);
void    rev_sort_3(t_stack *a, t_stack *b);
void    rev_sort_5(t_stack *a, t_stack *b);
void    push_min_a_simple(t_stack *a, t_stack *b);
void    push_max_b_simple(t_stack *a, t_stack *b);

//Petit grand choix
void	petit_choix(t_stack *a, t_stack *b);
void	big_choix(t_stack *a, t_stack *b);
int	    ft_brk(t_stack *a, t_stack *b);
void    rev_sort_b(t_stack *a, t_stack *b);

//Trier
int     trier(t_stack *s);
void    sort_a(t_stack *a, t_stack *b);
int     trier_a(t_stack *s);

//piv
void    find_piv(t_stack *stk);

int	    find_min_piv(t_stack *a);
int	    find_min_piv_bot(t_stack *a);
int     find_max_piv(t_stack *a);
int     find_max_piv_bot(t_stack *a);

//trier
int trier_a(t_stack *s);
int trier_b(t_stack *s);
void sort_a(t_stack *a, t_stack *b);
void sort_b(t_stack *a, t_stack *b);

//push_swap
int     push_piv_min(t_stack *a, t_stack *b);
int     push_piv_max(t_stack *a, t_stack *b);
void	push_swap_piv(t_stack *a, t_stack *b);

//PRINT
void	print_stack(t_stack *stk, char flag);
void	print_top(t_stack *a);
void	print_bot(t_stack *a);
void	print_top_bot(t_stack *a, char c);

//STACK and NODES
t_stack	*init_stack();
t_node	*ft_create_node(char *str);
t_stack	*ft_add_stack(t_stack *a, char *val);

//CHECK
int		ft_check_and_atoi(const char *str);
void	check_arg(char **av, t_stack *a);
void	check_double(t_node *a);
int		is_sorted(t_node *tmp);

//OPERATIONS
void	oper(char *flag, t_stack *a, t_stack *b);
void	ft_push(t_stack *a, t_stack *b,char flag);
void	ft_swap(t_stack *stk, char flag);
void    ft_ss(t_stack *a, t_stack *b);
void    ft_rot(t_stack *stk, char flag);
void    ft_rot_2(t_stack *a, t_stack *b);
void    ft_revrot(t_stack *stk, char flag);
void    ft_revrot_2(t_stack *a, t_stack *b);

#endif

/*
write ◦ read◦ malloc ◦ free◦ exit

 You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
• The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
• Instructions must be separaed by a ’\n’ and nothing else.
• The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
• In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

The game is composed of 2 stacks named a and b. • To start with:
◦ the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
◦ b is empty
• The goal is to sort in ascending order numbers into stack a.
• To do this you have the following operations at your disposal:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
