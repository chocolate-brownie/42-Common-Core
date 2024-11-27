/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:12:39 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 18:18:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The Turk algorithm works by dividing `stack_a` into smaller chunks based
on the indices of the elements. These chunks are pushed to `stack_b` in order,
starting with the smallest indices. Once all elements are in `stack_b`, they
are pushed back to `stack_a` in sorted order. During this process, the largest
element in `stack_b` is identified, moved to the top, and then pushed to
`stack_a`. This ensures that `stack_a` is fully sorted by the end of the
algorithm. */

void	turk_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;

	chunk_size = calculate_chunk_size(stack_size(*stack_a));
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	push_back_to_a(stack_a, stack_b);
}

int	calculate_chunk_size(int total_nodes)
{
	if (total_nodes <= 100)
		return (total_nodes / 5);
	else
		return (total_nodes / 11);
}

void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int	chunk_end;
	int	index;

	chunk_end = chunk_size;
	index = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index < chunk_end)
		{
			pb(stack_a, stack_b, true);
			index++;
			if (index == chunk_end)
				chunk_end += chunk_size;
		}
		else
			ra(stack_a, true);
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_index;

	while (*stack_b)
	{
		max_index = find_largest_index(*stack_b);
		while ((*stack_b)->index != max_index)
		{
			if (get_position(*stack_b, max_index) > stack_size(*stack_b) / 2)
				rrb(stack_b, true);
			else
				rb(stack_b, true);
		}
		pa(stack_a, stack_b, true);
	}
}

int	find_largest_index(t_list *stack)
{
	int	max_index;

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}
