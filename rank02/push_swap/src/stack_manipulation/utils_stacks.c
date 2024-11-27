/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:36:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 18:00:05 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_null(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

t_list	*create_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		error_exit("Error: Memory allocation failed");
	new_node->data = data;
	new_node->index = -1;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/* a function to maps each number in the stack to a normalized index based on
its position in the sorted order. This normalization simplifies comparisons and
makes sorting operations more efficient.*/
void	assign_indices(t_list *stack)
{
	t_list	*current;
	t_list	*checker;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		checker = stack;
		while (checker)
		{
			if (checker->data < current->data)
				index++;
			checker = checker->next;
		}
		current->index = index;
		current = current->next;
	}
}
