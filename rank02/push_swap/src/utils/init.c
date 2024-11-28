/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:36:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 12:10:58 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->bgn_list = NULL;
	stack_a->last = NULL;
	stack_a->list_size = 0;
	stack_b->bgn_list = NULL;
	stack_b->last = NULL;
	stack_b->list_size = 0;
}
