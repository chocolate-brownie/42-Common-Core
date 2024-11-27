/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:37:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 12:00:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_null(t_list **stack_a, t_list **stack_b)
{
	printf("🔧 Making stack_a & stack_b to NULL\n");
	*stack_a = NULL;
	*stack_b = NULL;
}

void	append_node(t_list **stack, int num)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free_resources(stack, NULL);
		error_exit();
	}
	new_node->data = num;
	new_node->index = -1;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}