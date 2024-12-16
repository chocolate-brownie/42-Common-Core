/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:29:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/16 19:26:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;
	int				len;

	len = stack_len(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	first = *stack;
	last = find_last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
