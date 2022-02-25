/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:12:42 by mpons             #+#    #+#             */
/*   Updated: 2022/02/25 19:38:53 by mpons            ###   ########.fr       */
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

typedef struct s_node	t_node;

struct s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};	

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
	int		min;
	int		max;
	int		pos;
	int		h_val;
	int		h_val_b;
	int		st_size;
	int		st_min;
	int		st_max;
	int		piv;
}	t_stack;

typedef struct s_ch
{
	int	x1;
	int	x2;
	int	y1;
	int	y1_b;
	int	y2;
	int	y2_b;
	int	a;
	int	b;
	int	c;
	int	d;
}	t_ch;

//STACK and NODES
t_stack	*init_stack(void);
t_node	*ft_create_node(char *str);
t_stack	*ft_add_stack(t_stack *a, char *val);
void	replace(t_stack *a);
void	take_info_stk(t_stack *stk);
void	find_values(t_stack *a, t_stack *b, t_ch *c);

//CHECK
int		ft_check_and_atoi(const char *str);
void	check_arg(char **av, t_stack *a);
void	check_double(t_node *a);
int		is_sorted(t_node *tmp);

//outils
void	err_m(void);
void	free_stack(t_stack *a);
int		v_absolute(int x);
int		bigger(int p, int q);

//OPERATIONS
void	oper(char *flag, t_stack *a, t_stack *b);
void	ft_push(t_stack *a, t_stack *b, char flag);
void	ft_swap(t_stack *stk, char flag);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_rot(t_stack *stk, char flag);
void	ft_rot_2(t_stack *a, t_stack *b);
void	ft_revrot(t_stack *stk, char flag);
void	ft_revrot_2(t_stack *a, t_stack *b);

//-----------ALGOS---------
//3 et 5
void	sort_3(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

//find_min_max_piv
int		find_min(t_stack *stk);
int		find_min_bot(t_stack *stk);
int		find_min_val(t_stack *stk);
int		find_max(t_stack *stk);
int		find_max_bot(t_stack *stk);
void	find_piv(t_stack *stk);

//find_piv_next
int		find_sous_piv(t_stack *a);
int		find_sous_piv_bot(t_stack *a);
int		find_next(int ref, t_stack *stk);

//push_swap
void	push_swap_piv(t_stack *a, t_stack *b, t_ch *c);
int		push_sous_piv(t_stack *a, t_stack *b, t_ch *c);
void	push_min_a(t_stack *a, t_stack *b);
void	push_max_b(t_stack *a, t_stack *b);
int		choix(t_stack *a, t_stack *b, t_ch *c);

#endif
