/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_smallest_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:09:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 18:10:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest_to_b(t_list **stack_a, t_list **stack_b)
{
	int	position;

	position = find_smallest_element(*stack_a);
	move_smallest_to_top(stack_a, position);
	pb(stack_a, stack_b, true);
}

void	move_smallest_to_top(t_list **stack, int position)
{
	int	size;

	size = stack_size(*stack);
	if (position <= size / 2)
	{
		while (position--)
			ra(stack, true);
	}
	else
	{
		while (position++ < size)
			rra(stack, true);
	}
}

int	find_smallest_element(t_list *stack)
{
	int	min_value;
	int	min_index;
	int	current_index;

	min_value = stack->data;
	min_index = 0;
	current_index = 0;
	while (stack)
	{
		if (stack->data < min_value)
		{
			min_value = stack->data;
			min_index = current_index;
		}
		stack = stack->next;
		current_index++;
	}
	return (min_index);
}
