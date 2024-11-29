/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:31:14 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/29 17:03:35 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_stack(t_stack *stack, int nbr)
{
    t_stack_node *new_node;

    new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        error_exit();
    new_node->nbr = nbr;
    new_node->next = stack->head;
    new_node->prev = NULL;
    if (stack->head)
        stack->head->prev = new_node;
    stack->head = new_node;
    if (!stack->tail)
        stack->tail = new_node;
    stack->size++;
}
