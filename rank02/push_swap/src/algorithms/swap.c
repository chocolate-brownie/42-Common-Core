/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:16:02 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/16 18:19:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Function to swap the first two nodes the stack passed as the argument */
static void	swap(t_stack_node **head)
{
	int				len;
	t_stack_node	*first;
	t_stack_node	*second;

	len = stack_len(*head);
	if (!*head || !head || len == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*head = second;
}

/* swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements). */
void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

/* swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements). */
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

/* sa and sb at the same time. */
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
