/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:59:40 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:41:31 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Converts string to long integer with whitespace handling
 * Used for checking integer overflow/underflow
 */
static long	ft_atol(const char *str)
{
	long	number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

/**
 * Initializes stack with command line values
 * Performs validation checks:
 * - Syntax validation
 * - Integer overflow/underflow
 * - Duplicate values
 */
void	initialize_stack(t_stack_node **stack_a, char **input,
		bool is_split_input)
{
	long	number;
	int		i;

	i = 0;
	if (is_split_input)
		i = 1;
	while (input[i])
	{
		if (validate_number_syntax(input[i]))
			handle_error_and_exit(stack_a, input, is_split_input);
		number = ft_atol(input[i]);
		if (number > INT_MAX || number < INT_MIN)
			handle_error_and_exit(stack_a, input, is_split_input);
		if (check_duplicate_value(*stack_a, (int)number))
			handle_error_and_exit(stack_a, input, is_split_input);
		add_node(stack_a, (int)number);
		i++;
	}
	if (is_split_input)
		deallocate_string_array(input);
}
