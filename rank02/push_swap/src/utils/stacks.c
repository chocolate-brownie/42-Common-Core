/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:48:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/15 15:14:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	create_stack(t_stack_node **a, char **argv)
{
	t_stack_node	*tail;
	t_stack_node	*new_node;

	tail = *a;
	while (*argv)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (!new_node)
			free_resources(a, argv);
		new_node->value = (int)ft_atol(*argv);
		new_node->next = NULL;
		new_node->prev = tail;
		if (!*a)
			*a = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		argv++;
	}
}

void	print_stack_details(t_stack_node *stack, char stack_name)
{
	int	position;

	position = 0;
	if (!stack)
	{
		printf("Stack %c is empty\n", stack_name);
		return ;
	}
	printf("Stack %c details:\n", stack_name);
	while (stack)
	{
		printf("Position %d: \n", position);
		printf("  Value: %d\n", stack->value);
		printf("  Current position: %d\n", stack->current_position);
		printf("  Final index: %d\n", stack->final_index);
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
	if (!stack)
	{
		printf("Stack is empty\n");
		return ;
	}
	for (t_stack_node *curr = stack; curr; curr = curr->next)
		printf("%d ", curr->value);
}
