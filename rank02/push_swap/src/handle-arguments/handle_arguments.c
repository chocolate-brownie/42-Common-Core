/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:41:31 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 12:39:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* @note
Write a function where you handle the case where if the argument is a single
string or whether the argument are bunch of argument counts. if the argument
is a single string such as "12 67 56 87" split it and push it to the stack_a
otherwise go through each argument starting from argv[1], validate them and push
them into stack_a
*/

void	handle_arguments(int argc, char **argv, t_stack *stack_a)
{
	char	**numbers;

	if (argc < 2)
		error_exit("[ERROR]: No arguments provided");
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			error_exit("[ERROR]: Memory allocation failed");
	}
	else
		numbers = argv + 1;
	validate_and_push(numbers, stack_a);
	if (argc == 2)
		free_resources(NULL, numbers);
}

void	validate_and_push(char **numbers, t_stack *stack_a)
{
	int	i;
	int	num;

	i = 0;
	while (numbers[i] != NULL)
	{
		if (!is_valid_number(numbers[i]))
			error_exit("[ERROR]: Invalid input");
		num = ft_atoi(numbers[i]);
		if (!add_to_stack(stack_a, num))
			error_exit("[ERROR]: Duplicate value or memory issue");
		i++;
	}
}

int	is_valid_number(const char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}
