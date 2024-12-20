/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:51:45 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:40:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_down(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				stack_size;

	if (!stack || !*stack)
		return ;
	stack_size = get_stack_size(*stack);
	if (stack_size == 1)
		return ;
	last_node = get_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	reverse_rotate_a(t_stack_node **stack_a, bool is_checker)
{
	rotate_down(stack_a);
	if (!is_checker)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_node **stack_b, bool is_checker)
{
	rotate_down(stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		bool is_checker)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	if (!is_checker)
		write(STDOUT_FILENO, "rrr\n", 4);
}
