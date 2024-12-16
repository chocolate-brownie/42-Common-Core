/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:59:54 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/16 23:55:31 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Turk Algorithm...
Push all but 3 nodes to B
Sort remaining 3 nodes in A
Main Sorting Phase - For each node in B, we need to:
	a) Initialize nodes metadata (init_nodes):
		- Set current positions for nodes in both stacks
		- Find target nodes in A for each node in B
		- Calculate push costs
		- Mark the cheapest node to move
	b) Move nodes optimally (move_nodes):
		- Find cheapest node to move
		- Rotate both stacks if possible (optimization)
		- Finish rotations for individual stacks
		- Push node from B to A
Final Phase:
	- Find smallest number
	- Rotate until smallest is at top z`*/
// 1. Main Algorithm Function
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a, false);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(a, b, false);
}

/* For EACH node in stack B, the `init_nodes(*a, *b)` function:
1. `set_current_position(a)` and `set_current_position(b)`:
   - Assigns positions (0, 1, 2...) to each node
   - Marks if each node is above/below median

2. `set_target_node(a, b)`:
   - For each B node, finds where it should go in A
   - Example: for 7 in B, it needs to go after 4 in A

3. `set_price(a, b)`:
   - Calculates cost of moving each B node to its target
   - Considers rotations needed in both stacks

4. `set_cheapest(b)`:
   - Marks which node in B is cheapest to move

Then `move_nodes(a, b)` executes the move for the cheapest node.

This process repeats for each node in B until B is empty. */
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
