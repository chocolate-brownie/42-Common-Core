/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:54:36 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:41:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	sort_five_elements(t_stack_node **stack_a, t_stack_node **stack_b)
{
	while (get_stack_size(*stack_a) > 3)
	{
		initialize_node_metadata(*stack_a, *stack_b);
		complete_rotation(stack_a, find_min_node(*stack_a), 'a');
		push_to_b(stack_b, stack_a, false);
	}
}
