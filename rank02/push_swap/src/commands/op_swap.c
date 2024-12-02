/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:31:08 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/12/02 11:16:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of the stack a. Does
nothing if there is only one or none. */
void	sa(t_stack *stack_a, bool print)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap_nodes(stack_a->head, stack_a->head->next);
	if (print)
		ft_putstr("sa\n");
}

/* sb (swap b) : Swap the first 2 elements at the top of the stack b.
Does nothing if there is only one or none. */
void	sb(t_stack *stack_b, bool print)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap_nodes(stack_b->head, stack_b->head->next);
	if (print)
		ft_putstr("sb\n");
}

/* ss : sa and sb at the same time. */
void	ss(t_stack *a, t_stack *b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_putstr("ss\n");
}
