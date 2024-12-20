/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:50 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:33:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	validate_input(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (false);
	return (true);
}

static char	**process_input(int argc, char **argv, bool *is_split_input)
{
	char	**input_array;

	if (argc == 2)
	{
		input_array = split_input(argv[1], ' ');
		if (!input_array)
			return (NULL);
		*is_split_input = true;
		return (input_array);
	}
	*is_split_input = false;
	return (argv + 1);
}

static void	execute_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	if (stack_size == 2)
		swap_a(stack_a, false);
	else if (stack_size == 3)
		sort_three_elements(stack_a);
	else
		sort_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**input_array;
	bool			is_split_input;

	stack_a = NULL;
	stack_b = NULL;
	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	input_array = process_input(argc, argv, &is_split_input);
	if (!input_array)
		handle_error_and_exit(NULL, NULL, NULL);
	initialize_stack(&stack_a, input_array, is_split_input);
	if (!is_stack_sorted(stack_a))
		execute_sort(&stack_a, &stack_b);
	deallocate_stack(&stack_a);
	deallocate_stack(&stack_b);
	return (EXIT_SUCCESS);
}
