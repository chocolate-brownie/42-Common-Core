/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:52:36 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 10:55:54 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_stack_node *node1, t_stack_node *node2)
{
	if (!node1 || !node2 || node1 == node2)
		return ;
	if (node1->next == node2)
		swap_adjacent_nodes(node1, node2);
	else
		swap_non_adjacent_nodes(node1, node2);
}

void	swap_adjacent_nodes(t_stack_node *node1, t_stack_node *node2)
{
	if (!node1 || !node2 || node1->next != node2)
		return ;
	node1->next = node2->next;
	node2->prev = node1->prev;
	if (node1->next)
		node1->next->prev = node1;
	if (node2->prev)
		node2->prev->next = node2;
	node2->next = node1;
	node1->prev = node2;
}

void	swap_non_adjacent_nodes(t_stack_node *node1, t_stack_node *node2)
{
	t_stack_node	*node1_next;
	t_stack_node	*node1_prev;
	t_stack_node	*node2_next;
	t_stack_node	*node2_prev;

	if (!node1 || !node2 || node1 == node2)
		return ;
	node1_next = node1->next;
	node1_prev = node1->prev;
	node2_next = node2->next;
	node2_prev = node2->prev;
	node1->next = node2_next;
	node1->prev = node2_prev;
	node2->next = node1_next;
	node2->prev = node1_prev;
	if (node1->next)
		node1->next->prev = node1;
	if (node1->prev)
		node1->prev->next = node1;
	if (node2->next)
		node2->next->prev = node2;
	if (node2->prev)
		node2->prev->next = node2;
}
