/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:48 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/10 01:45:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(const int argc, char *argv[])
{
	t_stack_node	*stack_a;

	stack_a = NULL;
	if (!is_consistent(argc, argv))
		error_exit();
	if (!control_arguments(argc, argv, &stack_a))
		error_exit();
	print_stack_details(stack_a, 'A');
	printf("\n");
	print_stack_normal(stack_a);
	free_stack(&stack_a);
	return (0);
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
