/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:36:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 17:05:49 by mgodawat         ###   ########.fr       */
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

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	printf("🖨️ Stack content:\n");
	while (current)
	{
		printf("Data: %d\n", current->data);
		printf("Index: %d\n", current->index);
		printf("Push Cost: %d\n", current->push_cost);
		printf("Above Median: %s\n", current->above_median ? "TRUE" : "FALSE");
		printf("Cheapest: %s\n", current->cheapest ? "TRUE" : "FALSE");
		printf("-------------------\n");
		current = current->next;
	}
	printf("🖨️ End of stack content\n");
}

void	print_stack_data(t_list *stack_a)
{
	t_list *current;

	current = stack_a;
	printf("🖨️ Stack A Data:\n");
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n🖨️ End of Stack A Data\n");
}