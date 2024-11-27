/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:54:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 14:19:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, bool print)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	temp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = temp;
	*stack_a = temp;
	temp->prev = NULL;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b, bool print)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	temp->prev = NULL;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
