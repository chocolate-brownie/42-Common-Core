/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:49:28 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:41:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap_nodes(t_stack_node **stack)
{
	int	stack_size;

	if (!stack || !*stack)
		return ;
	stack_size = get_stack_size(*stack);
	if (stack_size == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	swap_a(t_stack_node **stack_a, bool is_checker)
{
	swap_nodes(stack_a);
	if (!is_checker)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_stack_node **stack_b, bool is_checker)
{
	swap_nodes(stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_both(t_stack_node **stack_a, t_stack_node **stack_b,
		bool is_checker)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "ss\n", 3);
}
