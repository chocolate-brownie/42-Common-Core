/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:05:17 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 13:57:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The pa operation moves the top element of stack b to the top of stack a.
If stack b is empty, the function does nothing. */
void	pa(t_stack *a, t_stack *b, bool print)
{
	t_stack_node	*top_b;

	if (!b || b->size == 0)
		return ;
	top_b = b->head;
	b->head = top_b->next;
	if (b->head != NULL)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	b->size--;
	top_b->next = a->head;
	top_b->prev = NULL;
	if (a->head)
		a->head->prev = top_b;
	else
		a->tail = top_b;
	a->head = top_b;
	a->size++;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

/* pb (push b): Takes the first element on top of a and puts it on b.
Does nothing if a is empty. */
void	pb(t_stack *a, t_stack *b, bool print)
{
	t_stack_node	*top_a;

	if (!a || a->size == 0)
		return ;
	top_a = a->head;
	a->head = top_a->next;
	if (a->head)
		a->head->prev = NULL;
	else
		a->tail = NULL;
	a->size--;
	top_a->next = b->head;
	top_a->prev = NULL;
	if (b->head)
		b->head->prev = top_a;
	else
		b->tail = top_a;
	b->head = top_a;
	b->size++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
