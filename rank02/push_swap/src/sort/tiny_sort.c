/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:54:36 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 19:55:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Checks if stack is sorted in ascending order
 *
 * @param stack Stack to check
 * @return true if sorted or empty, false otherwise
 */
bool	is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/**
 * Finds node with highest value in stack
 *
 * @param stack Stack to search
 * @return Pointer to node with highest value, NULL if stack empty
 */
static t_stack_node	*find_max_node(t_stack_node *stack)
{
	int				highest_value;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	highest_value = INT_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->value > highest_value)
		{
			highest_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/**
 * Sorts a stack of three elements
 * Algorithm:
 * 1. If highest is at top, rotate to bottom
 * 2. If highest is in middle, reverse rotate to bottom
 * 3. Compare and swap first two elements if needed
 *
 * @param stack_a Pointer to stack to sort
 */
void	sort_three_elements(t_stack_node **stack_a)
{
	t_stack_node	*highest_node;

	highest_node = find_max_node(*stack_a);
	if (*stack_a == highest_node)
		rotate_a(stack_a, false);
	else if ((*stack_a)->next == highest_node)
		reverse_rotate_a(stack_a, false);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a, false);
}

/**
 * Handles sorting of five elements
 * Moves smallest elements to stack B until three remain
 *
 * @param stack_a Pointer to main stack
 * @param stack_b Pointer to auxiliary stack
 */
void	sort_five_elements(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (get_stack_size(*stack_a) > 3)
	{
		initialize_node_metadata(*stack_a, *stack_b);
		complete_rotation(stack_a, find_min_node(*stack_a), 'a');
		push_to_b(stack_b, stack_a, false);
	}
}
