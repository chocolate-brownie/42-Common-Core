/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:25:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 14:16:12 by mgodawat         ###   ########.fr       */
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

	init_stack_null(&stack_a, &stack_b);
	if (argc < 2)
		error_exit();
	stack_a = handle_arguments(argc, argv);
	if (stack_sorted(stack_a))
	{
		free_resources(&stack_a, NULL);
		return (0);
	}
	if (argc == 3)
		sort_two(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else if (argc == 5)
		sort_four(&stack_a, &stack_b);
	else if (argc == 6)
		sort_five(&stack_a, &stack_b);
	else
		turk_algorithm(&stack_a, &stack_b);
	free_resources(&stack_a, NULL);
	free_resources(&stack_b, NULL);
	return (0);
}
