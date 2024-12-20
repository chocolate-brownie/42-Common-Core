/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:11:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 14:30:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Updates position and median information for each node
 * @param stack Stack to update positions for
 */
void	update_positions(t_stack_node *stack)
{
	int	position;
	int	median_position;

	if (!stack)
		return ;
	position = 0;
	median_position = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->position = position;
		stack->is_above_median = (position <= median_position);
		stack = stack->next;
		position++;
	}
}

/**
 * Assigns target nodes in stack_a for each node in stack_b
 * Target is the smallest larger number, or the smallest number if none larger
 * @param stack_a Reference stack
 * @param stack_b Stack to assign targets for
 */
static void	assign_target_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_value;

	while (stack_b)
	{
		best_match_value = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			stack_b->target_node = find_min_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

/**
 * Calculates the cost of moving each node from stack_b to its target in stack_a
 * @param stack_a Reference stack
 * @param stack_b Stack to calculate costs for
 */
void	calculate_move_costs(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	while (stack_b)
	{
		stack_b->move_cost = stack_b->position;
		if (!stack_b->is_above_median)
			stack_b->move_cost = size_b - stack_b->position;
		if (stack_b->target_node->is_above_median)
			stack_b->move_cost += stack_b->target_node->position;
		else
			stack_b->move_cost += size_a - stack_b->target_node->position;
		stack_b = stack_b->next;
	}
}

/**
 * Marks the node with lowest move cost as cheapest
 * @param stack_b Stack to find cheapest node in
 */
void	mark_cheapest_moves(t_stack_node *stack_b)
{
	long			lowest_cost;
	t_stack_node	*cheapest_node;

	if (!stack_b)
		return ;
	lowest_cost = LONG_MAX;
	while (stack_b)
	{
		stack_b->is_cheapest = false;
		if (stack_b->move_cost < lowest_cost)
		{
			lowest_cost = stack_b->move_cost;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	cheapest_node->is_cheapest = true;
}

/**
 * Initializes all metadata for nodes in both stacks
 * Sets positions, targets, costs, and marks cheapest moves
 * @param stack_a Reference stack
 * @param stack_b Stack to initialize metadata for
 */
void	initialize_node_metadata(t_stack_node *stack_a, t_stack_node *stack_b)
{
	update_positions(stack_a);
	update_positions(stack_b);
	assign_target_nodes(stack_a, stack_b);
	calculate_move_costs(stack_a, stack_b);
	mark_cheapest_moves(stack_b);
}
