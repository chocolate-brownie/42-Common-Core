/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:21:16 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 13:50:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
The Turk Algorithm is a strategy for efficiently sorting large stacks.
It works by splitting the stack into chunks, sorting the chunks, and then
merging them back together with minimal operations. Here's how you can
implement it step by step.

Turk Algorithm Overview
Steps:
	Assign Index Values:
		Assign an index to each element in the stack based on its sorted
		order (smallest element gets 0,
			largest gets stack->size - 1).

	Divide into Chunks:
		Divide stack_a into smaller chunks based on the indices.
		Push elements from stack_a to stack_b chunk by chunk.

	Reinsert from stack_b:
		Use push_cost to identify the cheapest element to push back from
		stack_b to stack_a.
		Rotate the stacks as needed to minimize operations.

	Merge the Stack:
		Continue until all elements are back in stack_a in sorted order.
*/
void	turk_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;

	if (stack_a->size > 100)
		chunk_size = 20;
	else
		chunk_size = 5;
	assign_indices(stack_a);
	divide_into_chunks(stack_a, stack_b, chunk_size);
	reinsert_from_stack_b(stack_a, stack_b);
}

/* Assign indices to all elements in the stack based on their sorted order. */
void	assign_indices(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int				index;

	current = stack->head;
	while (current)
	{
		index = 0;
		compare = stack->head;
		while (compare)
		{
			if (compare->nbr < current->nbr)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

/* Push elements from stack_a to stack_b based on chunks
(e.g., 20 or 25 elements at a time for 100 or 500 total elements). */
void	divide_into_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int				current_chunk;
	t_stack_node	*current;

	current_chunk = 0;
	while (stack_a->size > 0)
	{
		current = stack_a->head;
		if (current->index >= current_chunk * chunk_size
			&& current->index < (current_chunk + 1) * chunk_size)
		{
			pb(stack_a, stack_b, true);
		}
		else
		{
			ra(stack_a, true);
		}
		if (stack_b->size == chunk_size)
			current_chunk++;
	}
}
