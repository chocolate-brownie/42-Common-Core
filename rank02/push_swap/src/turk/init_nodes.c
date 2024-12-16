/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 23:39:53 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/16 23:52:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* 1. `set_current_position(a)` and `set_current_position(b)`:
   - Assigns positions (0, 1, 2...) to each node
   - Marks if each node is above/below median */
void	set_current_position(t_stack_node *stack)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->current_position = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/* 2. set_target_node(a, b):
For each B node, finds where it should go in A
Example: for 7 in B, it needs to go after 4 in A */
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		target = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!b->above_median)
			b->push_price = len_b - b->current_position;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - b->target_node->current_position;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*cheapest;
	int				min_price;

	if (!b)
		return ;
	min_price = INT_MAX;
	while (b)
	{
		if (b->push_price < min_price)
		{
			min_price = b->push_price;
			cheapest = b;
		}
		b = b->next;
	}
	cheapest->cheapest = true;
}
