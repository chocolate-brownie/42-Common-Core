/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:05 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 14:11:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack, bool print)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack, bool print)
{
	t_list	*last;
	t_list	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	if (print)
		write(1, "rrb\n", 4);
}
void	rrr(t_list **stack_a, t_list **stack_b, bool print)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	if (print)
		write(1, "rrr\n", 4);
}
