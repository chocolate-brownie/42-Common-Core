/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:00:16 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 17:42:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
@note
The key optimization is that the algorithm:
   - Always keeps Stack A sorted
   - Finds optimal insertion points
   - Combines rotations when possible (rr, rrr)
   - Minimizes total moves by choosing cheapest operations

Initial Steps
- Keep 3 numbers in stack A
- Push all other numbers to stack B
- Sort the 3 numbers in stack A using tiny_sort

Main Algorithm
A. For each node in stack B, calculate:
   1. Current position in stack (above_median or below)
   2. Target position in stack A
   3. Cost to move to top of its stack
   4. Total cost of the operation

B. Find Target Node (where number should go in A):
   1. Look for smallest number larger than B's number
   2. If no larger number exists, target is the smallest number in A
   This ensures numbers are inserted in their correct sorted position

C. Calculate Costs:
   1. Cost to move node to top of B
   2. Cost to move target position to top of A
   3. Total cost = cost_B + cost_A

D. Choose Cheapest Move:
   1. Compare total costs of all possible moves
   2. Select node with lowest total cost

E. Execute Move:
   1. If both nodes above median: rotate both (rr)
   2. If both nodes below median: reverse rotate both (rrr)
   3. Finish individual rotations if needed
   4. Push from B to A

Final Step
- After B is empty, rotate A until smallest number is at top
*/
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len;
	t_stack_node	*smallest;

	len = stack_len(*a);
	while (len-- > 3)
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
	{
		while (*a != smallest)
			ra(a, false);
	}
	else
	{
		while (*a != smallest)
			rra(a, false);
	}
}
