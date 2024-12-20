/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:40:26 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:38:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* One function that transfers the top node from source stack to destination
stack handling all pointer adjustments and the manipulation of the doubly linked
list using this function you can easily create the pa and pb functions */
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

void	push_to_a(t_stack_node **stack_a, t_stack_node **stack_b,
		bool is_checker)
{
	push_node(stack_a, stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	push_to_b(t_stack_node **stack_b, t_stack_node **stack_a,
		bool is_checker)
{
	push_node(stack_b, stack_a);
	if (!is_checker)
		write(STDOUT_FILENO, "pb\n", 3);
}
