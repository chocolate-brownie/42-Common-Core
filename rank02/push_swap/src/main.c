/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:48 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/17 00:49:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	control_arguments(const int argc, char **argv, t_stack_node **a)
{
	char	**split_args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		printf("[DEBUGGING] Argument is a string\n");
		split_args = split(argv[1], ' ');
		if (!split_args)
			error_exit();
		if (!is_valid_input(split_args + 1) || duplicates(split_args + 1))
		{
			free_split(split_args);
			error_exit();
		}
		create_stack(a, split_args + 1);
		free_split(split_args);
	}
	else
	{
		if (!is_valid_input(argv + 1) || duplicates(argv + 1))
			error_exit();
		create_stack(a, argv + 1);
	}
	return (1);
}

int	main(const int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	if (!is_consistent(argc, argv))
		error_exit();
	if (!control_arguments(argc, argv, &stack_a))
		error_exit();
	print_stack_normal(stack_a);
	if (stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, true);
		else if (stack_len(stack_a) == 3)
			tiny_sort(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	print_stack_details(stack_a, 'A');
	print_stack_normal(stack_a);
	printf("\n");
	free_stack(&stack_a);
	return (0);
}
