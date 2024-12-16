/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:29:21 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/16 18:20:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* a function to take two nodes as src and dest and move the first node from the
src stack and push it to the dest if source is empty it should do nothing */
static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node;
	t_stack_node	*head_src;
	t_stack_node	*head_dest;

	head_src = *src;
	head_dest = *dest;
	if (!head_src)
		return ;
	node = head_src;
	head_src = head_src->next;
	if (head_src)
		head_src->prev = NULL;
	node->prev = NULL;
	node->next = head_dest;
	if (head_dest)
		head_dest->prev = node;
	*src = head_src;
	*dest = node;
}

/* push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty. push to A from B */
void pa(t_stack_node **a, t_stack_node **b, bool print) {
    push(a, b);
    if (print)
		write(1, "pa\n", 3);
}

/* push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty. push to B from A */
void pb(t_stack_node **b, t_stack_node **a, bool print) {
    push(b, a);
    if (print)
		write(1, "pb\n", 3);
}