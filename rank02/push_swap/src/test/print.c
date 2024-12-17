/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:46:58 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/17 16:47:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack_details(t_stack_node *stack, char stack_name)
{
	int	position;

	position = 0;
	if (!stack)
	{
		printf("Stack %c is empty\n", stack_name);
		return ;
	}
	printf("\n\nStack %c details:\n", stack_name);
	while (stack)
	{
		printf("Position %d: \n", position);
		printf("  Value: %d\n", stack->value);
		printf("  Current position: %d\n", stack->current_position);
		printf("  Push price: %d\n", stack->push_price);
		printf("  Above median: %d\n", stack->above_median);
		if (stack->target_node)
			printf("  Target value: %d\n", stack->target_node->value);
		printf("\n");
		stack = stack->next;
		position++;
	}
	printf("------------------------\n");
}

void	print_stack_normal(t_stack_node *stack)
{
	t_stack_node	*curr;

	if (!stack)
	{
		printf("Stack is empty\n");
		return ;
	}
	curr = stack;
	while (curr)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
}
