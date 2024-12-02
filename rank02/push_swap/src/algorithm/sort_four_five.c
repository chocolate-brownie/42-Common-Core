/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:58:32 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 12:17:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts a stack with 4 or 5 elements by:
1. Pushing the smallest elements to stack_b.
2. Sorting the remaining 3 elements in stack_a using sort_3.
3. Pushing the elements back from stack_b to stack_a. */
void	sort_four_five(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	smallest_index;

	while (stack_a->size > 3)
	{
		smallest_index = find_smallest_index(stack_a);
		move_to_top(stack_a, smallest_index);
		pb(stack_a, stack_b, true);
	}
	sort_3(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, true);
}

/* Finds the index of the smallest element in the stack. Returns the
position (0-based index) of the smallest element. */
int	find_smallest_index(t_stack *stack)
{
	t_stack_node	*current;
	int				smallest;
	int				smallest_index;
	int				index;

	current = stack->head;
	smallest = current->nbr;
	smallest_index = 0;
	index = 0;
	while (current)
	{
		if (current->nbr < smallest)
		{
			smallest = current->nbr;
			smallest_index = index;
		}
		current = current->next;
		index++;
	}
	return (smallest_index);
}

/* Rotates or reverse rotates the stack to move the element at the given
index to the top. */
void	move_to_top(t_stack *stack, int index)
{
	if (index <= stack->size / 2)
	{
		while (index-- > 0)
			ra(stack, true);
	}
	else
	{
		index = stack->size - index;
		while (index-- > 0)
			rra(stack, true);
	}
}
