/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:52:57 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 13:02:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_list **stack)
{
	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;

	int first = (*stack)->data;
	int second = (*stack)->next->data;
	int third = (*stack)->next->next->data;

	if (first > second && second < third && first < third)
		sa(stack, true);
}