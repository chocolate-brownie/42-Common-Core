/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:27:00 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 17:41:08 by mgodawat         ###   ########.fr       */
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
	The is_sorted function checks if stack_a is already sorted to avoid
	unnecessary operations.
Sorting Logic:
	For stacks with ≤5 elements, sort_small_stack is used.
	For larger stacks, sort_large_stack handles the sorting.
Resource Cleanup:
	free_stack is used to clean up allocated memory.
*/
/* Main logic for the Push_swap program */
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**parsed_argv;

	/* Step 1: Initialize stacks */
	ft_putstr_fd("🛠️  Initializing stacks...\n", 1);
	initialize_stacks(&stack_a, &stack_b);
	/* Step 2: Handle invalid input */
	ft_putstr_fd("🔍 Checking input validity...\n", 1);
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
	{
		ft_putstr_fd("⚠️  No valid arguments provided. Exiting.\n", 1);
		return (0);
	}
	/* Step 3: Parse and validate input */
	ft_putstr_fd("📜 Parsing and validating input...\n", 1);
	parsed_argv = parse_and_validate_input(&argc, argv);
	/* Step 4: Initialize stack */
	ft_putstr_fd("🗂️  Initializing stack with parsed input...\n", 1);
	initialize_stack(&stack_a, argc, parsed_argv);
	/* Step 5: Check if already sorted */
	ft_putstr_fd("🔢 Checking if the stack is already sorted...\n", 1);
	if (is_stack_sorted(stack_a))
	{
		ft_putstr_fd("✅ Stack is already sorted. Cleaning up and exiting.\n",
			1);
		clean_up(&stack_a, &stack_b, argc, parsed_argv);
		return (0);
	}
	/* Step 6: Sort the stack */
	ft_putstr_fd("🚀 Sorting the stack...\n", 1);
	sort_stack(&stack_a, &stack_b);
	/* Step 7: Clean up resources */
	ft_putstr_fd("🧹 Cleaning up resources...\n", 1);
	clean_up(&stack_a, &stack_b, argc, parsed_argv);
	ft_putstr_fd("🏁 Program finished successfully!\n", 1);
	return (0);
}
