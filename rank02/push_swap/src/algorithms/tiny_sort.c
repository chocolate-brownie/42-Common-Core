/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:47:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/16 19:55:05 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, true);
	else if ((*a)->next == highest)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest;
	t_stack_node	*current;

	if (!stack)
		return (NULL);
	highest = stack;
	current = stack;
	while (current)
	{
		if (current->value > highest->value)
			highest = current;
		current = current->next;
	}
	return (highest);
}
