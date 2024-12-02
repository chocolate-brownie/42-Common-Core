/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:50:41 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 11:59:43 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts a stack with exactly 3 elements in ascending order. Uses minimal
operations (sa, ra, rra) to handle all possible permutations. The stack must
have exactly 3 elements for this function to work.
Case: 2 1 3 -> 1 2 3
Case: 3 2 1 -> 2 3 1 -> 1 2 3
Case: 3 1 2 -> 1 2 3
Case: 2 3 1 -> 3 2 1 -> 1 2 3
Case: 1 3 2 -> 1 2 3 */
void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->nbr;
	second = stack_a->head->next->nbr;
	third = stack_a->head->next->next->nbr;
	if (first > second && second < third && first < third)
		sa(stack_a, true);
	else if (first > second && second > third)
	{
		sa(stack_a, true);
		rra(stack_a, true);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, true);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, true);
		ra(stack_a, true);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, true);
}
