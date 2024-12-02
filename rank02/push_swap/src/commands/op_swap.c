/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:31:08 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/12/02 09:51:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. */
void	sa(t_stack *stack, bool print)
{
	if (stack->size < 2)
		return ;
	t_stack_node *first = stack->head;
	t_stack_node *second = first->next;
}