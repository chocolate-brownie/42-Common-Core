/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:52:57 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 13:38:03 by mgodawat         ###   ########.fr       */
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
	int	first;
	int	second;
	int	third;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack, true);
	else if (first > second && second > third)
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if (first > second && second < third && first > third)
		ra(stack, true);
	else if (first < second && second > third && first < third)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (first < second && second > third && first > third)
		rra(stack, true);
}

void	turk_algorithm(t_list **stack_a, t_list **stack_b)
{
	/* 	Step 1: Partition stack_a into smaller chunks and push to stack_b */
	partition_stack(stack_a, stack_b);
	/* 	Step 2: Sort each chunk in stack_b */
	sort_stack_b(stack_b);
	/* 	Step 3: Merge back sorted elements from stack_b into stack_a */
	merge_stacks(stack_a, stack_b);
}
