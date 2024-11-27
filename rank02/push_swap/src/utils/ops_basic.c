/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:47:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 13:53:28 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swaps the first two elements at the top of stack_a. */
void	sa(t_list **stack, bool print)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

/* swaps the first two elements at the top of stack_b */
void	sb(t_list **stack, bool print)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
	if (print)
		write(1, "sb\n", 3);
}
/* simultaneously swaps the first two elements of both stack_a and stack_b */
void	ss(t_list **stack_a, t_list **stack_b, bool print)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (print)
		write(1, "ss\n", 3);
}
