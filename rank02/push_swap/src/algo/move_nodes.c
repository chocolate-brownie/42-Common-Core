/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:17:35 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 17:42:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

static void	finish_rotation(t_stack_node **stack, t_stack_node *top_node,
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

/* @note
The fundamental goal of this function is to move one node from stack B to
its correct position in stack A in the most efficient way possible.

Base Principles:
	We always want to move the cheapest node (least operations)
	Before pushing a node, both the node and its target need to be at the top
	We can save operations by rotating both stacks at once when possible

STEPS:
Get the node that's cheapest to move
We have four possible cases:
	1. Both nodes above median -> use rr
	2. Both nodes below median -> use rrr
	3. Nodes on opposite sides -> move separately
	4. One or both nodes already at top -> move what's needed

Initial state:
Stack A: [5, 2, 1]
Stack B: [4, 3]

1. Find cheapest node:
   - Node 4 needs to go before 5
   - Both 4 and 5 are above median

2. Apply strategy:
   - Can use rotate_both (rr)
   - One rr operation moves both into position

3. Push:
   - pa moves 4 to A

Final state:
Stack A: [4, 5, 2, 1]
Stack B: [3]
*/
void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}
