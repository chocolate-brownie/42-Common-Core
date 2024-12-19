/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:40:26 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/19 19:40:58 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Transfers the top node from source stack to destination stack
 * Handles all pointer adjustments for doubly linked list
 *
 * @param dest_stack Pointer to destination stack head
 * @param src_stack Pointer to source stack head
 * @return void
 */
static void	push_node(t_stack_node **dest_stack, t_stack_node **src_stack)
{
	t_stack_node	*node_to_transfer;

	if (!src_stack || !*src_stack)
		return ;
	node_to_transfer = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	node_to_transfer->prev = NULL;
	if (!*dest_stack)
	{
		*dest_stack = node_to_transfer;
		node_to_transfer->next = NULL;
	}
	else
	{
		node_to_transfer->next = *dest_stack;
		node_to_transfer->next->prev = node_to_transfer;
		*dest_stack = node_to_transfer;
	}
}

/**
 * Pushes top element from stack B to stack A
 * Prints 'pa' if not in checker mode
 *
 * @param stack_a Pointer to stack A head
 * @param stack_b Pointer to stack B head
 * @param is_checker Flag indicating if in checker mode
 */
void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
		bool is_checker)
{
	push_node(stack_a, stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "pa\n", 3);
}

/**
 * Pushes top element from stack A to stack B
 * Prints 'pb' if not in checker mode
 *
 * @param stack_b Pointer to stack B head
 * @param stack_a Pointer to stack A head
 * @param is_checker Flag indicating if in checker mode
 */
void	push_to_b(t_stack_node **stack_b, t_stack_node **stack_a,
		bool is_checker)
{
	push_node(stack_b, stack_a);
	if (!is_checker)
		write(STDOUT_FILENO, "pb\n", 3);
}
