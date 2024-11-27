/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:48:42 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 18:12:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		sa(stack, true);
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack, true);
	else if (a > b && b > c)
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if (a > b && b < c && a > c)
		ra(stack, true);
	else if (a < b && b > c && a < c)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (a < b && b > c && a > c)
		rra(stack, true);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b, true);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b, true);
	pa(stack_a, stack_b, true);
}
