/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:47:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 14:21:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b, bool print)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
