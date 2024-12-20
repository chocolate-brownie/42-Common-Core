/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:39:02 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/20 17:24:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	handle_error_and_exit(t_stack_node **stack_a, char **input_array,
		bool is_split_input)
{
	deallocate_stack(stack_a);
	if (is_split_input)
		deallocate_string_array(input_array);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

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
