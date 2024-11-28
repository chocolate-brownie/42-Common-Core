/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:32:21 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 12:38:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(t_stack *stack, int num)
{
	t_list	*new_node;

	if (is_duplicate_in_stack(stack, num))
		return (0);
	new_node = create_stack_node(num);
	if (!new_node)
		return (0);
	insert_node_to_stack(stack, new_node);
	return (1);
}

int	is_duplicate_in_stack(t_stack *stack, int num)
{
	t_list	*current;

	current = *(stack->bgn_list);
	while (current != NULL)
	{
		if (*(int *)(current->content) == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	insert_node_to_stack(t_stack *stack, t_list *new_node)
{
	new_node->next = *(stack->bgn_list);
	new_node->prev = NULL;
	if (*(stack->bgn_list) != NULL)
		(*(stack->bgn_list))->prev = new_node;
	*(stack->bgn_list) = new_node;
	if (stack->list_size == 0)
		stack->last = new_node;
	stack->list_size += 1;
}

t_list	*create_stack_node(int num)
{
	t_list	*new_node;
	int		*content;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	content = (int *)malloc(sizeof(int));
	if (!content)
	{
		free(new_node);
		return (NULL);
	}
	*content = num;
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
