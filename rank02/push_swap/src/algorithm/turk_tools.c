/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:49:19 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 13:54:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculate how many rotations are needed to bring a node to
the top of the stack. */
void	calculate_push_cost(t_stack *stack)
{
	t_stack_node	*current;
	int				size;
	int				position;

	current = stack->head;
	size = stack->size;
	position = 0;
	while (current)
	{
		if (position <= size / 2)
			current->push_cost = position;
		else
			current->push_cost = size - position;
		current = current->next;
		position++;
	}
}

/*Find the node in stack_b with the smallest push_cost and return it.*/
t_stack_node	*find_cheapest_node(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;

	current = stack->head;
	cheapest = current;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

/*Reinsert the elements from stack_b to stack_a in sorted
order by finding and pushing the cheapest node.*/
void	reinsert_from_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*cheapest;

	while (stack_b->size > 0)
	{
		calculate_push_cost(stack_b);
		cheapest = find_cheapest_node(stack_b);
		while (stack_b->head != cheapest)
		{
			if (cheapest->push_cost <= stack_b->size / 2)
				rb(stack_b, true);
			else
				rrb(stack_b, true);
		}
		pa(stack_a, stack_b, true);
	}
}
