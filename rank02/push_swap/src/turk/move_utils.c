/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:07:02 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/17 00:23:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* @note
rotate_both and reverse_rotate_both:
	Rotate both stacks simultaneously when possible
	Update positions after each rotation
	Stop when either node reaches its target position

finish_rotation:
	Completes individual stack rotations
	Chooses direction based on whether node is above/below median
	Different rotation commands for stack A and B

return_cheapest:
	Finds the node marked as cheapest
	Returns that node for moving */

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rr(a, b, true);
		set_current_position(*a);
		set_current_position(*b);
	}
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
	{
		rrr(a, b, true);
		set_current_position(*a);
		set_current_position(*b);
	}
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
