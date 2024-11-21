/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:37:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/21 18:01:37 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack_null(t_list **stk_a, t_list **stk_b)
{
    *stk_a = NULL;
    *stk_b = NULL;
}

t_list *create_node(int data)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        error_exit();
    new->data = data;
    new->index = -1;
    new->push_cost = 0;
    new->above_median = false;
    new->cheapest = false;
    new->target_node = NULL;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}
