/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:39:02 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 15:41:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Deallocates a dynamically allocated 2D string array
 * Note: Array pointer must be offset by -1 due to special array structure
 * where actual data starts at index -1
 *
 * @param string_array Array of strings to be freed
 */
void	deallocate_string_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * Deallocates all memory associated with a stack
 * Iterates through the linked list and frees each node
 *
 * @param stack Pointer to the stack head pointer
 */
void	deallocate_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		ft_bzero(current, sizeof(t_stack_node));
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

/**
 * Handles error cases by cleaning up memory and exiting
 * Prints error message to stderr and performs appropriate cleanup
 * based on input source
 *
 * @param stack_a Pointer to main stack
 * @param input_array Array of input strings
 * @param is_split_input Flag indicating if input was split from single argument
 */
void	handle_error_and_exit(t_stack_node **stack_a, char **input_array,
		bool is_split_input)
{
	deallocate_stack(stack_a);
	if (is_split_input)
		deallocate_string_array(input_array);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/**
 * Validates the syntax of a number string
 * Checks if the string represents a valid integer format
 *
 * @param number_str String to validate
 * @return 0 if valid, 1 if invalid
 */
int	validate_number_syntax(char *number_str)
{
	size_t	i;
	long	num;

	if (!number_str || !*number_str)
		return (1);
	i = 0;
	if (number_str[i] == '+' || number_str[i] == '-')
		i++;
	if (!ft_isdigit(number_str[i]))
		return (1);
	while (number_str[i])
	{
		if (!ft_isdigit(number_str[i]))
			return (1);
		i++;
	}
	num = ft_atoi(number_str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

/**
 * Checks for duplicate values in the stack
 *
 * @param stack Stack to check
 * @param value Value to look for
 * @return true if duplicate found, false otherwise
 */
bool	check_duplicate_value(t_stack_node *stack, int value)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->value == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}
