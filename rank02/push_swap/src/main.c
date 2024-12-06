/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:15:48 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/06 15:35:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(const int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!control_arguments(argc, argv, &stack_a))
		exit(EXIT_FAILURE);
	free_stack(&stack_a);
	return (0);
}

int control_arguments(const int argc, char **argv, t_stack_node **a)
{
    char **split_args;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    if (argc == 2)
    {
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
