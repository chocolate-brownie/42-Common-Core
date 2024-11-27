/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:02:52 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 18:03:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting_algorithm(t_list **stack_a, t_list **stack_b,
		int stack_count)
{
	if (stack_count == 2)
		sort_two(stack_a);
	else if (stack_count == 3)
		sort_three(stack_a);
	else if (stack_count == 4)
		sort_four(stack_a, stack_b);
	else if (stack_count == 5)
		sort_five(stack_a, stack_b);
	else
		turk_algorithm(stack_a, stack_b);
}
