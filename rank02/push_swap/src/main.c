/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:25:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 12:45:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* @note - step 1
Decalre pointers to two linked lists, one for stack_a and one for stack_b
and initialize the pointers as NULL to avoid undefined behaviour to indicate
that we are starting with empty stacks */

/* @note - step 2
Handle input count errors, argument count must be 2 or more, and the second
input must not be empty, if there's input errors return error */

/* @note - step 3
if the numbers as argv[i] "MULTIPLE ARGUMENTS" and push them into the
stack_a, if the numbers are as "SINGLE STRING" argv[1] split the string
and push them into the stack_a

	-- Handle integer overflows, duplicates, and sytax errors, (input must only
	contains digits, '+' or '-' signs if errors found, free stack A and return
	error)
	-- Check for each input if it's a long integer, if it is convert it into
	a long integer

if everything is good append the numbers as nodes to the stack_a */

/* @note - step 4
Check if the stack_a is sorted already, if not sorted implement the sorting
algorithms...
	-- check for 2 numbers ? if so simply swap the numebrs
	-- check for 3 numbers ? if so implement simple sort three algorithm
	-- check if the stack has more that 3 numbers ? if so turk algorithm */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	printf("🛠️ Running main\n\n");
	init_stack_null(&stack_a, &stack_b);
	if (argc < 2)
	{
		printf("🛠️ Error: No arguments provided\n");
		return (0);
	}
	stack_a = handle_arguments(argc, argv);
	printf("\n\n🖨 Initial stack_a contents: ");
	print_stack(stack_a);
	if (stack_sorted(stack_a))
	{
		printf("🛠️ Stack is already sorted. Exiting...\n");
		free_resources(&stack_a, NULL);
		return (0);
	}
	if (argc == 4)
		sort_three(&stack_a);
	else
		turk_algorithm(&stack_a, &stack_b);
	free_resources(&stack_a, NULL);
	free_resources(&stack_b, NULL);
	printf("\n\n🛠️ main End\n");
	return (0);
}
