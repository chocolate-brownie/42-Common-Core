/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:51:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:40 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_up(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				stack_size;

	if (!stack || !*stack)
		return ;
	stack_size = get_stack_size(*stack);
	if (stack_size == 1)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	rotate_a(t_stack_node **stack_a, bool is_checker)
{
	rotate_up(stack_a);
	if (!is_checker)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_stack_node **stack_b, bool is_checker)
{
	rotate_up(stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		bool is_checker)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "rr\n", 3);
}
