/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:59:54 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/17 00:22:14 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* @note
1. Get length of stack A
2. Push all nodes except 3 to stack B
	- If you have 7 numbers, 4 go to B, 3 stay in A
3. Sort the remaining 3 numbers in stack A using the tiny_sort algorithm
4. For each node in stack B:
	- Calculate positions, targets, and costs (init_nodes)
	- Move the cheapest node to its correct position in A (move_nodes)
	- Repeat until B is empty
5. After B is empty:
	- Update positions of nodes in A
	- Find the smallest number in A
6. Final step - rotate A until smallest is at top:
	- If smallest is in top half, rotate forward (ra)
	- If smallest is in bottom half, rotate backward (rra) */
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a, true);
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
			ra(a, true);
	else
		while (*a != smallest)
			rra(a, true);
}

/* @note
This function handles moving a node from stack B to its target position in
stack A in the most efficient way. It:
	- Finds the cheapest node to move from B
	- Rotates both stacks optimally (using double rotations when possible)
	- Does final individual rotations if needed
	- Pushes the node from B to A */
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
	pa(a, b, true);
}

/* @note
For EACH node in stack B, the `init_nodes(*a, *b)` function:
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
