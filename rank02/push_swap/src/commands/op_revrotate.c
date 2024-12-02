/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:31:50 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 13:56:31 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra (reverse rotate a): Shifts all elements of the stack down one position.
the stack a. The last element becomes the first. */
void	rra(t_stack *a, bool print)
{
	t_stack_node	*old_tail;

	if (!a || a->size < 2)
		return ;
	old_tail = a->tail;
	a->tail = old_tail->prev;
	a->tail->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = a->head;
	a->head->prev = old_tail;
	a->head = old_tail;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/* rrb (reverse rotate b): Shifts all the elements of the stack b one position
downwards. the stack b. The last element becomes the first. */
void	rrb(t_stack *b, bool print)
{
	t_stack_node	*old_tail;

	if (!b || b->size < 2)
		return ;
	old_tail = b->tail;
	b->tail = old_tail->prev;
	b->tail->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = b->head;
	b->head->prev = old_tail;
	b->head = old_tail;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/* rrr : rra and rrb at the same time. */
void	rrr(t_stack *a, t_stack *b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
