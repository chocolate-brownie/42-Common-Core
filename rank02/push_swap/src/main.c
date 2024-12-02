/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:27:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 16:32:54 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Initialization:
	Both stack_a and stack_b are initialized using initialize_stack.
Argument Validation:
	check_arguments ensures the inputs are valid integers without duplicates.
	initialize_stack_with_args populates stack_a with the input values.
Sorting Check:
	The is_sorted function checks if stack_a is already sorted to avoid unnecessary operations.
Sorting Logic:
	For stacks with ≤5 elements, sort_small_stack is used.
	For larger stacks, sort_large_stack handles the sorting.
Resource Cleanup:
	free_stack is used to clean up allocated memory.
*/
int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	initialize_stack(&stack_a);
	initialize_stack(&stack_b);
	if (argc < 2)
		return (0);
	check_arguments(argc, argv);
	initialize_stack_with_args(&stack_a, argc, argv);
	if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	if (stack_a.size <= 5)
		sort_small_stack(&stack_a, &stack_b, stack_a.size);
	else
		sort_large_stack(&stack_a, &stack_b, stack_a.size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

static int	is_sorted(t_stack *stack)
{
	t_node *current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}