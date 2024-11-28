/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 17:25:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes the stack pointers to null.
** Ensures both stack_a and stack_b are ready to use.
*/
void	init_stack_null(t_stack **stack_a, t_stack **stack_b)
{
	ft_putstr_fd("[RUNNING] init_stack_null\n", 1);
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
	ft_putstr_fd("[ENDING] init_stack_null\n", 1);
}
