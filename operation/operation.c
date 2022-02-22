/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:12:28 by mpons             #+#    #+#             */
/*   Updated: 2022/01/28 12:52:26 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	oper(char *flag, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(flag, "pb", 2))
		ft_push(a, b, 'b');
	if (!ft_strncmp(flag, "pa", 2))
		ft_push(b, a, 'a');
	if (!ft_strncmp(flag, "sa", 2))
		ft_swap(a, 'a');
	if (!ft_strncmp(flag, "sb", 2))
		ft_swap(b, 'b');
	if (!ft_strncmp(flag, "ss", 2))
		ft_ss(a, b);
	if (!ft_strncmp(flag, "ra", 2))
		ft_rot(a, 'a');
	if (!ft_strncmp(flag, "rb", 2))
		ft_rot(b, 'b');
	if (!ft_strncmp(flag, "rr", 2) && ft_strlen(flag) == 2)
		ft_rot_2(a, b);
	if (!ft_strncmp(flag, "rra", 3))
		ft_revrot(a, 'a');
	if (!ft_strncmp(flag, "rrb", 3))
		ft_revrot(b, 'b');
	if (!ft_strncmp(flag, "rrr", 3))
		ft_revrot_2(a, b);
}
