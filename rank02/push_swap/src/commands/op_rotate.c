/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:26:24 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 11:34:08 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra (rotate a): Shifts all the elements of the stack a up by one position.
The first element becomes the last. */
void	ra(t_stack *a, bool print)
{
	t_stack_node	*old_head;

	if (!a || a->size < 2)
		return ;
	old_head = a->head;
	a->head = old_head->next;
	a->head->prev = NULL;
	old_head->next = NULL;
	old_head->prev = a->tail;
	a->tail->next = old_head;
	a->tail = old_head;
	if (print)
		ft_putstr("ra\n");
}

/* rb (rotate b) : Shifts all the elements of the stack b one position upwards.
The first element becomes the last one. */
void	rb(t_stack *b, bool print)
{
	t_stack_node	*old_head;

	if (!b || b->size < 2)
		return ;
	old_head = b->head;
	b->head = old_head->next;
	b->head->prev = NULL;
	old_head->next = NULL;
	old_head->prev = b->tail;
	b->tail->next = old_head;
	b->tail = old_head;
	if (print)
		ft_putstr("rb\n");
}

/* rr : ra and rb at the same time. */
void	rr(t_stack *a, t_stack *b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		ft_putstr("rr\n");
}
