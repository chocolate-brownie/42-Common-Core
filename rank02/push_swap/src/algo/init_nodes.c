/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:01:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 17:44:19 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
write a function which sets up all the necessary information we need to make
optimal decisions about which number to move next.

We need to know for each number: set_current_position
	- Its exact position in the stack (0, 1, 2, etc.)
	- Whether it's above or below the middle of the stack
	Why? Because this helps calculate how many moves it will take to get to the
	top
*/
void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
/*
For each number in B, we need to know: set_target_node
	- Where should it go in stack A?
	- Which number in A should it be placed under? (target_node)
*/
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
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
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}
/*
The purpose of set_price is to calculate the total cost (number of operations)
needed to move a number from stack B to its correct position in stack A.
	- Calculates cost to move B node to top
	- Adds cost to get target A node to top
	- Considers position relative to median

Stack A: [3, 7, 9]  (len_a = 3)
Stack B: [4, 8, 2]  (len_b = 3)

For number 4 in B:
Position: 0 (top)
Target: 7 in stack A
Cost calculation:
- Cost in B: 0 (already at top)
- Cost in A: 1 (one move to get 7 to top)
Total cost: 0 + 1 = 1

For number 8 in B:
Position: 1 (middle)
Target: 9 in stack A
Cost calculation:
- Cost in B: 1 (one move to top)
- Cost in A: 2 (two moves to get 9 to top)
Total cost: 1 + 2 = 3
*/
static void	set_price(t_stack_node *a, t_stack_node *b)
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
/*
Among all numbers in B: set_cheapest
	- Compare their total costs
	- Mark the one with lowest cost as cheapest

Stack A: [3, 7, 9]
Stack B: [4, 8, 2]

For each number in B, we calculate:
	4: target=7, cost=1+1=2 moves
	8: target=9, cost=2+2=4 moves
	2: target=3, cost=3+1=4 moves

Result: We choose to move 4 first because it's cheapest
*/
static void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*best_match_node;
	long			best_match_value;

	if (NULL == b)
		return ;
	current = b;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	best_match_value = LONG_MAX;
	best_match_node = NULL;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	if (best_match_node)
		best_match_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}