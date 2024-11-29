/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milan-godawatta <milan-godawatta@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/29 17:34:20 by milan-godaw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes the stack pointers to null.
** Ensures both stack_a and stack_b are ready to use.
*/
void	init_stack_null(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = (t_stack *)malloc(sizeof(t_stack));
	*stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack_a) || !(*stack_b))
	{
		ft_putstr_fd("Error allocating memory to stack_a & stack_b", 2);
		exit(1);
	}
	(*stack_a)->head = NULL;
	(*stack_a)->tail = NULL;
	(*stack_a)->size = 0;
	(*stack_b)->head = NULL;
	(*stack_b)->tail = NULL;
	(*stack_b)->size = 0;
}
