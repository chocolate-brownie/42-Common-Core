/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:24:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 14:25:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Rotates both stacks until target nodes reach top
 *
 * @param stack_a Pointer to stack A head
 * @param stack_b Pointer to stack B head
 * @param current_node Node being moved
 */
static void	rotate_stacks_up(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *current_node)
{
	while (*stack_a != current_node->target_node && *stack_b != current_node)
		rotate_both(stack_a, stack_b, false);
	update_positions(*stack_a);
	update_positions(*stack_b);
}

/**
 * Reverse rotates both stacks until target nodes reach top
 *
 * @param stack_a Pointer to stack A head
 * @param stack_b Pointer to stack B head
 * @param current_node Node being moved
 */
static void	rotate_stacks_down(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *current_node)
{
	while (*stack_a != current_node->target_node && *stack_b != current_node)
		reverse_rotate_both(stack_a, stack_b, false);
	update_positions(*stack_a);
	update_positions(*stack_b);
}

/**
 * Completes rotation to bring target node to top
 *
 * @param stack Pointer to stack head
 * @param top_node Node to bring to top
 * @param stack_id Identifier for stack ('a' or 'b')
 */
void	complete_rotation(t_stack_node **stack, t_stack_node *top_node,
		char stack_id)
{
	while (*stack != top_node)
	{
		if (stack_id == 'a')
		{
			if (top_node->is_above_median)
				rotate_a(stack, false);
			else
				reverse_rotate_a(stack, false);
		}
		else if (stack_id == 'b')
		{
			if (top_node->is_above_median)
				rotate_b(stack, false);
			else
				reverse_rotate_b(stack, false);
		}
	}
}

/**
 * Moves node from stack B to correct position in stack A
 * Uses node metadata to determine optimal movement
 *
 * @param stack_a Pointer to stack A head
 * @param stack_b Pointer to stack B head
 */
static void	transfer_node(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_b);
	if (cheapest_node->is_above_median
		&& cheapest_node->target_node->is_above_median)
		rotate_stacks_up(stack_a, stack_b, cheapest_node);
	else if (!cheapest_node->is_above_median
		&& !cheapest_node->target_node->is_above_median)
		rotate_stacks_down(stack_a, stack_b, cheapest_node);
	complete_rotation(stack_b, cheapest_node, 'b');
	complete_rotation(stack_a, cheapest_node->target_node, 'a');
	push_to_a(stack_a, stack_b, false);
}

/**
 * Main sorting algorithm for stack
 * Implements optimized sorting strategy:
 * 1. Push nodes to B (except 3)
 * 2. Sort remaining 3 nodes in A
 * 3. Move nodes back to A in sorted order
 * 4. Rotate A to position smallest at top
 *
 * @param stack_a Pointer to stack A head
 * @param stack_b Pointer to stack B head
 */
void	sort_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*min_node;
	int				stack_a_size;

	stack_a_size = get_stack_size(*stack_a);
	if (stack_a_size == 5)
		sort_five_elements(stack_a, stack_b);
	else
	{
		while (stack_a_size-- > 3)
			push_to_b(stack_b, stack_a, false);
	}
	sort_three_elements(stack_a);
	while (*stack_b)
	{
		initialize_node_metadata(*stack_a, *stack_b);
		transfer_node(stack_a, stack_b);
	}
	update_positions(*stack_a);
	min_node = find_min_node(*stack_a);
	if (min_node->is_above_median)
		while (*stack_a != min_node)
			rotate_a(stack_a, false);
	else
		while (*stack_a != min_node)
			reverse_rotate_a(stack_a, false);
}
